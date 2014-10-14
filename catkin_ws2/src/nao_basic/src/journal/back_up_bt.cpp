#include <nao_basic/motions_common.h>
#include <nao_basic/robot_config.h>

#include "ros/ros.h"
#include <actionlib/client/simple_action_client.h>
#include <std_srvs/Empty.h>
#include <std_msgs/Int8.h>
#include <geometry_msgs/Pose2D.h>
#include <behavior_trees/rosaction.h>

#include <iostream>
#include <unistd.h>
#include <math.h>

#include <alproxies/almotionproxy.h>

#include <alerror/alerror.h>



class BackUp : ROSAction
{
public:
	bool init_;
    int battery_level;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;
    AL::ALMotionProxy* motion_proxy_ptr;

    BackUp(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
		execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            motion_proxy_ptr = new AL::ALMotionProxy(robot_ip, 9559);
        }

    ~BackUp()
        {
        motion_proxy_ptr->stopMove();
        delete motion_proxy_ptr;

		}

	void initialize()
		{
			sleep(1.0);
            AL::ALValue stiffness_name("Body");
            AL::ALValue stiffness(1.0f);
            AL::ALValue stiffness_time(1.0f);
            motion_proxy_ptr->stiffnessInterpolation(stiffness_name,
                                                     stiffness,
                                                     stiffness_time);
            motion_proxy_ptr->moveInit();
            set_feedback(RUNNING);
		}

	void finalize()
		{
        //init_ = false;
        }

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Back Up -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Back Up -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
            }
            motion_proxy_ptr->post.moveTo(-0.1, 0.0, 0.0);
            //if (execute_time_.toSec() >2)	{
              //  motion_proxy_ptr->stopMove();
                set_feedback(SUCCESS);
                return 1;
           // }
            set_feedback(SUCCESS);
            finalize();
            return 1;

		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}



};

int main(int argc, char** argv)
{
    std::cout << "Back Up Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("BackUp") + "_" + agent); // name used for bt.txt
    BackUp server(ros::this_node::getName(), robot_ip);
	ros::spin();
	return 0;
}
