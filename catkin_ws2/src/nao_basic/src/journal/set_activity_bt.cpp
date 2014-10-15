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
#include <alproxies/alspeechrecognitionproxy.h>
#include <alproxies/almemoryproxy.h>
#include <alerror/alerror.h>
#include <alvalue/alvalue.h>
ros::Publisher activity_pub;


class SetActivity : ROSAction
{
public:
	bool init_;
	ros::Duration execute_time_;
    ros::Time time_at_pos_;
    std_msgs::String msg;

    std::vector<std::string> activity_vocabulary;
    std::vector<std::string> word_recognized;
    float confidence_val;
    AL::ALValue al_word_vector;
    AL::ALSpeechRecognitionProxy* speech_rec_proxy_ptr;
    AL::ALMemoryProxy* memory_proxy_ptr;
    AL::ALBehaviorManagerProxy* behavior_proxy_ptr;



    SetActivity(std::string name, std::string robot_ip):
		ROSAction(name),
		init_(false),
        execute_time_((ros::Duration) 0),
        time_at_pos_((ros::Time) 0)
		{
			std::cout << "Robot ip to use is: " << robot_ip << std::endl;
            speech_rec_proxy_ptr = new AL::ALSpeechRecognitionProxy(robot_ip, 9559);
            memory_proxy_ptr = new AL::ALMemoryProxy(robot_ip, 9559);
            behavior_proxy_ptr = new AL::ALBehaviorManagerProxy(robot_ip, 9559);

            //al_word_vector = new AL::ALValue();

    }

    ~SetActivity()
		{
        speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");
		}

	void initialize()
		{
            //sleep(1.0);
			set_feedback(RUNNING);
            //behavior_proxy_ptr->stopAllBehaviors();

		}

	void finalize()
		{
        speech_rec_proxy_ptr->unsubscribe("LastWordRecognized");

		}

	int executeCB(ros::Duration dt)
		{
            std::cout << "**Set Activity -%- Executing Main Task, elapsed_time: "
			          << dt.toSec() << std::endl;
            std::cout << "**Set Activity -%- execute_time: "
			          << execute_time_.toSec() << std::endl;
			execute_time_ += dt;

			if (!init_)
			{
				initialize();
				init_ = true;
                // = {"car", "50", "house","50"};
              //  activity_vocabulary.assign(0,"yes");
               // activity_vocabulary.assign(1,"no");
              //  activity_vocabulary.assign(2,"50");

                    activity_vocabulary.push_back("Picture Game");
                    activity_vocabulary.push_back("Dance");
                    activity_vocabulary.push_back("Sleep");
                    activity_vocabulary.push_back("Sit Down");
                    activity_vocabulary.push_back("Stand Up");
                    //activity_vocabulary.push_back("Lie Down");
                    activity_vocabulary.push_back("Say Goodbye");
                    //activity_vocabulary.push_back("Stop");
                    activity_vocabulary.push_back("Sound");
                    activity_vocabulary.push_back("Eyes");




                speech_rec_proxy_ptr->setWordListAsVocabulary(activity_vocabulary);
                speech_rec_proxy_ptr->subscribe("LastWordRecognized");

			}


            al_word_vector = memory_proxy_ptr->getData("LastWordRecognized");
            word_recognized =  memory_proxy_ptr->getData("LastWordRecognized");
            confidence_val = al_word_vector[1];

            //std::cout << "String Recognized!:" << memory_proxy_ptr->getData("WordRecognized") << std::endl;
            std::cout << "\033[1;32m Word Recognised:\033[0m"<< word_recognized[0] << std::endl;
            std::cout << "\033[1;32m Confidence:\033[0m" << confidence_val << std::endl;


            if(confidence_val > 0.25){// al_word_vector[1] contains the confidence of the most recognized word WHIC IS CONTAINED IN al_word_vector[0]
            msg.data =  word_recognized[0];
            activity_pub.publish(msg);
            }
            set_feedback(RUNNING);

            return 1;
		}

	void resetCB()
		{
			execute_time_ = (ros::Duration) 0;
		}



};

int main(int argc, char** argv)
{
    std::cout << "Set Ativity Started" << std::endl;
	// specify which options are available as cmd line arguments
	setupCmdLineReader();
	// read agent id from command line parameters (--agent=mario)
	std::string agent = readAgentFromCmdLine(argc, argv);
	// read robot ip from command line parameters (--robot_ip=192.168.0.100 for example)
	std::string robot_ip = readRobotIPFromCmdLine(argc, argv);
    ros::init(argc, argv, std::string("SetActivity") + "_" + agent); // name used for bt.txt
    ros::NodeHandle n;
    activity_pub  =   n.advertise<std_msgs::String>("activity", 1000);
    SetActivity server(ros::this_node::getName(), robot_ip);
	ros::spin();
	return 0;
}
