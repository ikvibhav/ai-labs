#include<iostream>
#include <string>
#include <vector>
#include "robot.h"
#include "chartodir.cpp"
#include "resetgrid.cpp"
#include "displaygrid.cpp"

#if !defined(height) || !defined(width)
#define height 14
#define width 22
#endif

int main(){
	std::vector<Robot> player;

	char field[height][width];
	
	// reset grid to all . values
	resetgrid(field);

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

	field[player[0].getY()][player[0].getX()]='H';
	for(i=1;i<=in_no_robot;i++)
	{
		field[player[i].getY()][player[i].getX()]='R';
	}
	displaygrid(field);

	return 0;
}
