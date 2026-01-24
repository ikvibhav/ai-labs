#include<iostream>
#define height 14
#define width 22

#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
	int x,y;
	char dir;
public:
	int status;	// Indicates if the robot is out of the field. 1 => out of field, 0 => inside field  

	Robot(); 	//default Constructor

	Robot(int in_x,int in_y,char in_dir); // Constructor with input

	void init_Robot(int in_x,int in_y,char in_dir); // Robot Position and direction initialisation
	
	int moveForward(); //moveForward. Position changes depending on robot direction.

	int moveBackward(); //moveBackward. Position changes depending on robot direction.

	int turnLeft(); //Change direction counterclockwise

	int turnRight(); //Change direction clockwise

	int getX(); //returns the x position

	int getY(); //returns the y position

	char getDir();//return the direction

};//end of Robot class
#endif
