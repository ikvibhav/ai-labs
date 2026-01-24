#include<iostream>
#include <string>
#include <vector>

#include "robot.h"


Robot::Robot() //default Constructor
{
	x=rand() % width;
	y=rand() % height;
	dir = 'n';
	status = 0;

}

Robot::Robot(int in_x,int in_y,char in_dir) // Constructor with input
{
	x=in_x;
	y=in_y;
	dir=in_dir;
}
void Robot::init_Robot(int in_x,int in_y,char in_dir) // Initialise the robot position
{
	x=in_x;
	y=in_y;
	dir=in_dir;
}

	int Robot:: moveForward() //moveForward. It will change the position depending on the direction the robot facing.
	{
		if (dir=='n')
		{
			if (y==0)
			{
				y=y;//already at the top edge
				status=1; //set flag to out of the field
			}
			else
			{
				y=y-1; //decrement y positon by one
			}
		}
		
		if (dir=='s')
		{
			if (y==height)
			{
				y=y;//already at the bottom edge
				status=1; //set flag to out of the field
			}
			else
			{
				y=y+1; //increment y positon by one
			}
		}

		if (dir=='w')
		{
			if (x==0)
			{
				x=x;//already at the left edge
				status=1; //set flag to out of the field
			}
			else
			{
				x=x-1; //decrement x positon by one
			}
		}
		if (dir=='e')
		{
			if (x==width)
			{
				x=x;//already at the right edge
				status=1; //set flag to out of the field
			}
			else
			{
				x=x+1; //increment x positon by one
			}
		}

		return status;
	}


	int Robot::moveBackward() //moveBackward It will change the position depending on the direction the robot facing.
	{
		if (dir=='n')
		{
			if (y==height)
			{
				y=y;//already at the bottom edge
				status=1; //set flag to out of the field
			}
			else
			{
				y=y+1; //increment y positon by one
			}
		}
		
		if (dir=='s')
		{
			if (y==0)
			{
				y=y;//already at the top edge
				status=1; //set flag to out of the field
			}
			else
			{
				y=y-1; //decrement y positon by one
			}
		}

		if (dir=='w')
		{
			if (x==width)
			{
				x=x;//already at the right edge
				status=1; //set flag to out of the field
			}
			else
			{
				x=x+1; //increment x positon by one
			}
		}
		if (dir=='e')
		{
			if (x==0)
			{
				x=x;//already at the left edge
				status=1; //set flag to out of the field
			}
			else
			{
				x=x-1; //increment x positon by one
			}
		}
		return status;

	}

	int Robot:: turnLeft() //Change direction counterclockwise
	{
		switch (dir)
		{
			case 'n': dir ='w';break;
			case 'w': dir ='s';break;
			case 's': dir ='e';break;
			case 'e': dir ='n';break;
		}
		return 0;
	}

	int Robot:: turnRight() //Change direction clockwise
	{
		switch (dir)
		{
			case 'n': dir ='e';break;
			case 'e': dir ='s';break;
			case 's': dir ='w';break;
			case 'w': dir ='n';break;
		}
		return 0;
	}



	int Robot:: getX() //return x position
	{
		//printf("X position %d \n",x);
		return x;
	}

	int Robot:: getY() //return y position
	{
		//printf("Y position %d \n",y);
		return y;
	}

	char Robot:: getDir() //return direction
	{
		//printf("Direction %c \n",dir);
		return dir;
	}

