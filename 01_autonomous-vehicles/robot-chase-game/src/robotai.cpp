#include<iostream>
#include <string>
#include <vector>
#include "robotai.h"


void robot_ai(std::vector<Robot> &player) 
{	
	unsigned int i=1;
	for(i=1;i<player.size();i++)
	{
		int dx=player[0].getX()-player[i].getX(); 
		int dy=player[0].getY()-player[i].getY(); 
		//printf("dx=%d dy=%d \n", abs(dx),abs(dx));
		//Need to check here
		if((float)1.5*abs(dy)>=(float)abs(dx)) //reduce distance of y if its greater than x
		{
			if (dy>0)		//Human robot lies below the AI robot
			{
				switch (player[i].getDir())
				{
					case 'n': player[i].moveBackward(); break;
					case 's': player[i].moveForward();	break;
					case 'w': player[i].turnLeft();		break;
					case 'e': player[i].turnRight();	break;
				}
			}
			else			//Human robot lies above the AI robot
			{
				switch (player[i].getDir())
				{
					case 'n': player[i].moveForward();	break;
					case 's': player[i].moveBackward(); break;
					case 'w': player[i].turnRight();	break;
					case 'e': player[i].turnLeft();		break;
				}

			}
		}
		else
		{
			if (dx>0)		//Human robot lies on the right of the AI robot
			{
				switch (player[i].getDir())
				{
					case 'n': player[i].turnRight();	break;
					case 's': player[i].turnLeft();		break;
					case 'w': player[i].moveBackward();	break;
					case 'e': player[i].moveForward();	break;
				}

			}
			else			//Human robot lies on the left of the AI robot
			{
				switch (player[i].getDir())
				{	
					case 'n': player[i].turnLeft();		break;
					case 's': player[i].turnRight();	break;
					case 'w': player[i].moveForward();	break;
					case 'e': player[i].moveBackward();	break;
				}
			}

		}
	}
}