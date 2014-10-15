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

#include <alproxies/albehaviormanagerproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/albatteryproxy.h>
#include <alerror/alerror.h>



class IsActivityGoodBye : ROSAction
{
public:
	bool init_;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;
    std::string last_activity_name;
    AL::ALBehaviorManagerProxy* behavior_proxy_ptr;

    IsActivityGoodBye(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
        execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
        {
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(robot_ip, 9559);

		}

    ~IsActivityGoodBye()
		{

		}

	void initialize()
		{
			sleep(1.0);
			set_feedback(RUNNING);
		}

	void finalize()
		{
        //last_activity_name = "none";
		}

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Is Activity GoodBye-%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Is Activity GoodBye-%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
                //initialize();
				init_ = true;
                last_activity_name = "none";
			}

            //set_feedback(RUNNING);
            std::cout <<"Is Say Goodbye?: " << last_activity_name << std::endl;

            if(last_activity_name.compare("Say Goodbye") == 0){
                set_feedback(SUCCESS);
                finalize();
                return 1;
                }else{
                behavior_proxy_ptr->stopBehavior("goodbye");

                set_feedback(FAILURE);
                finalize();
                return 1;
                }
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
    std::cout << "Is Activity GoodBye Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("IsActivityGoodbye") + "_" + agent); // name used for bt.txt
    IsActivityGoodBye server(ros::this_node::getName(), robot_ip);
    ros::NodeHandle n;
    ros::Subscriber activity_name =
        n.subscribe<std_msgs::String>("activity" , 1,
                                           &IsActivityGoodBye::SetActivity, &server);
	ros::spin();
	return 0;
}
