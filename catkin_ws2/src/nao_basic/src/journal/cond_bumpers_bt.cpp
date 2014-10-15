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

#include <alproxies/almemoryproxy.h>
#include <alproxies/alsensorsproxy.h>
#include <alerror/alerror.h>



class Bumpers : ROSAction
{
public:
	bool init_;
    int battery_level;
    float l_bumper;
    float r_bumper;
    ros::Duration execute_time_;
	ros::Time time_at_pos_;
    AL::ALMemoryProxy* memory_proxy_ptr;
    AL::ALSensorsProxy* sensors_proxy_ptr;
    Bumpers(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
		execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            memory_proxy_ptr = new AL::ALMemoryProxy(robot_ip, 9559);
            sensors_proxy_ptr = new AL::ALSensorsProxy(robot_ip, 9559);
            //memory_proxy_ptr->subscribeToEvent("RightBumperPressed","Bumpers","bumper_callback");

    }

    ~Bumpers()
		{
            delete memory_proxy_ptr;
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
            std::cout << "**Bumpers Monitor -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Bumpers Monitor -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
                //sensors_proxy_ptr->subscribe("RightBumperPressed", 1,1.0);
			}
            l_bumper = memory_proxy_ptr->getData("LeftBumperPressed");
            r_bumper = memory_proxy_ptr->getData("RightBumperPressed");
            if(l_bumper > 0.5f || r_bumper > 0.5f){
                std::cout << "Bumper(s) Hit" << std::endl;
                set_feedback(SUCCESS);
                return 0;
            }


            std::cout << "Bumpers OK" << std::endl;
            set_feedback(FAILURE);
            return 0;
		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}
    int bumper_callback(){
        std::cout << "**Bumper Pressed "<< std::endl;
        return 1;
        }

};

int main(int argc, char** argv)
{


    std::cout << "Bumpers Monitor Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("Bumpers") + "_" + agent); // name used for bt.txt
    Bumpers server(ros::this_node::getName(), robot_ip);
    ros::spin();
	return 0;
}
