//=================================================================
// Grid.h
// Author:	Robert House
// Date:	13 OCT 2014
//
// Holds the Robot and Treasure objects. Finds the shortest path for
// the robot to get to the treasure and stores the path taken as a
// string vector. The shortest path is solved recursively.
//
// Assumptions:
//				- The robot can "see" where the treasure is located.
//				- The algorithm will always return the shortest path
//				for the given (x1, y1) (x2, y2).
//				- The entity object is NOT unique per recursive call.
//				- The movement string can be passed on in the recursive
//				calls
//
//=================================================================

#ifndef GRID_H
#define GRID_H

#include <vector>
#include "Entity.h"
#include <ostream>
#include <string>

class Grid
{
	static const int MAXSIZE = 20; // dim = abs(-MAXSIZE x MAXSIZE)
	
	// For easy recognition instead of having just numbers and not having to
	// do any macros
	enum Move
	{
		NORTH = 1,
		SOUTH = -1,
		EAST = 1,
		WEST = -1
	};

public:
	Grid(int x1, int y1, int x2, int y2);
	~Grid();

	// Public helper function in case I wanted to chance the location of any of the
	// entities before running again.
	void RobotSearch();

	// << overload
	friend std::ostream& operator<<(std::ostream &os, const Grid &grid);

private:
	int pGridSize = MAXSIZE;
	Entity *pRobot;
	Entity *pTreasure;
	std::vector<std::string> pPaths;
	
	// I only seed the spatial location of the robot. I do not wish
	// to pass different robot objects through, as that would just be
	// a waste. The actual robot object is just a side effect of what
	// I was originally planning. This leaves it open to some extendibilty.
	//
	// For example: you could create a game where the player moves an object,
	// and AI is controlled by the shortest path algorithm.
	void pRobotSearch(int x, int y, std::string path);

	// check to see if the location is on top of the treasure
	bool pCheckCollision(int x, int y, const Entity *entity);
};

#endif