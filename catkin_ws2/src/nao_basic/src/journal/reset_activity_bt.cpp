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

#include <alproxies/altexttospeechproxy.h>
#include <alerror/alerror.h>
ros::Publisher activity_pub;



class ResetActivity : ROSAction
{
public:
	bool init_;
    int battery_level;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;
    std_msgs::String msg;

    AL::ALTextToSpeechProxy* speech_proxy_ptr;

    ResetActivity(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
		execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            speech_proxy_ptr = new AL::ALTextToSpeechProxy(robot_ip, 9559);

    }

    ~ResetActivity()
		{
        delete speech_proxy_ptr;
        }

	void initialize()
		{
			sleep(1.0);
			set_feedback(RUNNING);
		}

	void finalize()
		{
        //delete speech_proxy_ptr;
        //delete behavior_proxy_ptr;
		}

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Reset Activity -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Reset Activityt -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
            }
            speech_proxy_ptr->say("Activity Reset");
            msg.data = "";//I reset the activity after he's done
            activity_pub.publish(msg);//so it does not say the sentence more than once
            set_feedback(SUCCESS);
            return 1;

		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}



};

int main(int argc, char** argv)
{
    std::cout << "Reset Activity Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("ResetActivity") + "_" + agent); // name used for bt.txt
    ResetActivity server(ros::this_node::getName(), robot_ip);
    ros::NodeHandle n;
    activity_pub  =   n.advertise<std_msgs::String>("activity", 1000);
	ros::spin();
	return 0;
}
