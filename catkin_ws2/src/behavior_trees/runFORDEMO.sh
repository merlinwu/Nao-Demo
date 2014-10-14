gnome-terminal -x rosrun behavior_trees behavior_trees --agent=B&
gnome-terminal -x rosrun nao_basic BallTrackerBT --color=red --robot_ip=192.168.0.196 --agent=B&
gnome-terminal -x rosrun nao_basic BallThrowerBT --robot_ip=192.168.0.196 --agent=B&
gnome-terminal -x rosrun nao_basic HandMoverBT --robot_ip=192.168.0.196 --agent=B&
gnome-terminal -x rosrun nao_basic MoveForwardBT --robot_ip=192.168.0.196 --agent=B&
gnome-terminal -x rosrun nao_basic WalkerBT --robot_ip=192.168.0.196 --agent=B&
gnome-terminal -x rosrun nao_basic MissionFailedBT --robot_ip=192.168.0.196 --agent=B&


