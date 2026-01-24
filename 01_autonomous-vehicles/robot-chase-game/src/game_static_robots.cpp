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

	char field[height][width]={'.'};

	//reset grid to initialize
	resetgrid(field);


	int in_no_robot;
	std::cout<<"How many robots do you want?"<<std::endl;
	std::cin>>in_no_robot;
	//Robot player[in_no_robot];
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
	cout << endl;

	std::string human_input;
	int invalid_human_input=0;
	std::string left("left");
	std::string right("right");
	std::string forward("forward");
	std::string backward("backward");

	//The convention, lose =-1, cont = 0 and win = 1 is followed
	/*When the Human controlled robot moves outside the grid,
	  then moveforward and movebackward set the gamestatus to 1.
	*/
	int gamestatus=0;


	do{
		std::cout<<"Input command for robot (forward/backward/left/right)"<<std::endl;
		//Human input
		//This loop will run until the user enters a valid human input
		do{
			std::cin >> human_input;

			if (human_input.compare(left) == 0)
			{
				invalid_human_input=0;
				gamestatus=player[0].turnLeft();
			}
			else if (human_input.compare(right) == 0)
			{
				invalid_human_input=0;
				gamestatus=player[0].turnRight();
			}
			else if (human_input.compare(forward) == 0)
			{
				invalid_human_input=0;
				gamestatus=player[0].moveForward();
			}
			else if (human_input.compare(backward) == 0)
			{
				invalid_human_input=0;
				gamestatus=player[0].moveBackward();
			}
			else 
			{
				std::cout<<"Input valid command for robot (forward/backward/left/right)"<<std::endl;
				invalid_human_input=1;
			}
		}while(invalid_human_input);		


	    //check if the positions overlap
		for(i=1;i<=in_no_robot;i++)
		{
			if((player[0].getY()==player[i].getY())&&(player[0].getX()==player[i].getX()))
			{
				gamestatus =-1;
			}

		}

		// Reset the grid with . values
		resetgrid(field);

		// Update the grid with the new positions of the robots
		for(i=1;i<=in_no_robot;i++)
		{
			field[player[i].getY()][player[i].getX()]='R';
		}

		// Display human robot only if the game is still continuing
		if (gamestatus==0)
		{
			field[player[0].getY()][player[0].getX()]='H';
		}
		
		//display the new updated grid
		displaygrid(field);
		cout << endl;

	}while(gamestatus==0);

	if (gamestatus==1)
	{
		printf("You win!!\n");
	}
	else
	{	
		printf("You lose.\n");
	}
	return 0;
}
