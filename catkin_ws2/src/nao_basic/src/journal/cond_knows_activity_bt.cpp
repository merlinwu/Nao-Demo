#include <nao_basic/motions_common.h>
#include <nao_basic/robot_config.h>

#include "ros/ros.h"
#include <actionlib/client/simple_action_client.h>
#include <std_srvs/Empty.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Pose2D.h>
#include <behavior_trees/rosaction.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#include <alproxies/almotionproxy.h>
#include <alproxies/albatteryproxy.h>
#include <alerror/alerror.h>



class KnowsActivity : ROSAction
{
public:
	bool init_;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;
    std::string last_activity_name;
    KnowsActivity(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
        execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
        {
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            last_activity_name = "";

		}

    ~KnowsActivity()
		{

		}

	void initialize()
		{
			sleep(1.0);
			set_feedback(RUNNING);
		}

	void finalize()
		{

		}

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Knows Activity -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Knows Activity -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
                last_activity_name = "";
			}

            set_feedback(RUNNING);

            if(last_activity_name.compare("") != 0){
            set_feedback(SUCCESS);
            std::cout <<"Activity Set: " << last_activity_name << std::endl;
            return 1;
            }
            std::cout <<"Activity Unkown: " << std::endl;
            set_feedback(FAILURE);
            return 1;
		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}

    void SetActivity(const std_msgs::String::ConstPtr &msg)
        {
            last_activity_name = msg->data;
        }

};

int main(int argc, char** argv)
{
    std::cout << "Knows Activity Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("KnowsActivity") + "_" + agent); // name used for bt.txt
    KnowsActivity server(ros::this_node::getName(), robot_ip);
    ros::NodeHandle n;
    ros::Subscriber activity_name =
        n.subscribe<std_msgs::String>("activity" , 1,
                                           &KnowsActivity::SetActivity, &server);
	ros::spin();
	return 0;
}