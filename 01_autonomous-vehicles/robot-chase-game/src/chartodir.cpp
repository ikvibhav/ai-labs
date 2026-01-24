#include<iostream>
#include <string>
#include <vector>

using namespace std;

std::string chartodir(char dir)
{
	std::string s;
	switch (dir)
	{
		case 'n': s ="north";	break;
		case 'w': s ="west";	break;
		case 's': s ="south";	break;
		case 'e': s ="east";	break;
	}
	return s;
}