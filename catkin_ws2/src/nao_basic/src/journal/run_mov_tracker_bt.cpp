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
#include <alproxies/albehaviormanagerproxy.h>
#include <alerror/alerror.h>



class RunDance : ROSAction
{
public:
	bool init_;
    int battery_level;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;

    AL::ALTextToSpeechProxy* speech_proxy_ptr;
    AL::ALBehaviorManagerProxy* behavior_proxy_ptr;

    RunDance(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
		execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            speech_proxy_ptr = new AL::ALTextToSpeechProxy(robot_ip, 9559);
            behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(robot_ip, 9559);

    }

    ~RunDance()
		{
        delete speech_proxy_ptr;
        delete behavior_proxy_ptr;
        }

	void initialize()
		{
			sleep(1.0);
			set_feedback(RUNNING);
            behavior_proxy_ptr->stopAllBehaviors();// stops possible behaviors running from choregraphe

		}

	void finalize()
		{
        //delete speech_proxy_ptr;
        //delete behavior_proxy_ptr;
        init_ = false;
        speech_proxy_ptr->say("Finalising the movement tracker");
        behavior_proxy_ptr->stopAllBehaviors();
		}

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Run Mov Tracker -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Run Mov Tracker -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
                speech_proxy_ptr->say("OK, I'm gonna start the movement tracker");

            }
            behavior_proxy_ptr->runBehavior("mov_tracker");
            set_feedback(RUNNING);//this never return success
            return 1;

		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}



};

int main(int argc, char** argv)
{
    std::cout << "Run Mov Tracker Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("RunMovTracker") + "_" + agent); // name used for bt.txt
    RunDance server(ros::this_node::getName(), robot_ip);
	ros::spin();
	return 0;
}
