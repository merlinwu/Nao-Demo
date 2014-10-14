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
#include <alproxies/albatteryproxy.h>
#include <alerror/alerror.h>



class BatteryLevel : ROSAction
{
public:
	bool init_;
    int battery_level;
	ros::Duration execute_time_;
	ros::Time time_at_pos_;
	AL::ALMotionProxy* motion_proxy_ptr;
    AL::ALBatteryProxy* battery_proxy_ptr;
    BatteryLevel(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
		execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            motion_proxy_ptr = new AL::ALMotionProxy(robot_ip, 9559);
            battery_proxy_ptr = new AL::ALBatteryProxy(robot_ip, 9559);
		}

    ~BatteryLevel()
		{
			delete motion_proxy_ptr;
            delete battery_proxy_ptr;
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
            std::cout << "**Battery Level -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Battery Level -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
                battery_level = 0;
               // battery_proxy_ptr.enablePowerMonitoring(true);
			}

            battery_level = battery_proxy_ptr->getBatteryCharge();

            std::cout <<"The battery is at: " << battery_level<< "%"<< std::endl;
            set_feedback(RUNNING);

            if(battery_level<5){
            set_feedback(SUCCESS);
            std::cout <<"The battery level is low " << std::endl;
            return 0;
            }
            std::cout <<"The battery level is OK " << std::endl;
            set_feedback(FAILURE);
            return 1;
		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}



};

int main(int argc, char** argv)
{
    std::cout << "Battery Level Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("BatteryLevel") + "_" + agent); // name used for bt.txt
    BatteryLevel server(ros::this_node::getName(), robot_ip);
	ros::spin();
	return 0;
}
