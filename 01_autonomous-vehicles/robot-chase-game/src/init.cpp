#include<iostream>
#include <string>
#include <vector>

#include "robot.h"
#include "chartodir.cpp"

int main(){
	std::vector<Robot> player;

	int in_no_robot;
	std::cout<<"How many robots do you want?"<<std::endl;
	std::cin>>in_no_robot;

	int i=0;
	int in_robot_x;
	int in_robot_y;
	char in_robot_dir;

	std::cout<<"For the human controlled robot:"<<std::endl;
	std::cout<<"Enter x position."<<std::endl;
	std::cin>>in_robot_x;
	std::cout<<"Enter y position."<<std::endl;
	std::cin>>in_robot_y;
	std::cout<<"Enter direction."<<std::endl;
	std::cin>>in_robot_dir;
	Robot human(in_robot_x,in_robot_y,in_robot_dir);
	player.push_back(human);
	i++;

	for(i=1;i<=in_no_robot;i++)
	{
		std::cout<<"For robot "<<i<<":"<<std::endl;
		std::cout<<"Enter x position."<<std::endl;
		std::cin>>in_robot_x;
		std::cout<<"Enter y position."<<std::endl;
		std::cin>>in_robot_y;
		std::cout<<"Enter direction."<<std::endl;
		std::cin>>in_robot_dir;
		Robot ai_robot(in_robot_x,in_robot_y,in_robot_dir);
		player.push_back(ai_robot);

	}

	std::cout<<"The human controlled robot: ("<<player[0].getX()<<":"<<player[0].getY()<<") facing "<<chartodir(player[0].getDir())<<"."<<std::endl;
	for(i=1;i<=in_no_robot;i++)
	{
		std::cout<<"Robot "<<i<<": ("<<player[i].getX()<<":"<<player[i].getY()<<") facing "<<chartodir(player[i].getDir())<<"."<<std::endl;
	}



	return 0;
}