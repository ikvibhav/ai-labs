#include<iostream>
#include <string>
#include <vector>

using namespace std;

void resetgrid(char field[height][width])
{
	for (int v = 0; v < height; v++)
	{
		for (int h = 0; h < width; h++)
		{
			field[v][h]='.';
		}
	}
}