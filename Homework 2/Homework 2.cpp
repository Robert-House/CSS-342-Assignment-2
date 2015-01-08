// Homework 2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Grid.h"

Grid *grid;

int main()
{
	int x1, y1, x2, y2, pause;

	std::cout << "Please enter 4 numbers (x1, y1, x2, y2): ";
	std::cin >> x1 >> y1 >> x2 >> y2;
	
	grid = new Grid(x1, y1, x2, y2);

	std::cout << *grid << std::endl;
	
	std::cout << "Type '0' then press 'ENTER' to continue" << std::endl;
	std::cin >> pause;
	
	return 0;
}

