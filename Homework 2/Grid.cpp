#include "Grid.h"

Grid::Grid(int x1, int y1, int x2, int y2)
{
	pRobot = new Entity(x1, y1);
	pTreasure = new Entity(x2, y2);

	RobotSearch();
}

Grid::~Grid() 
{
	// Clean up objects
	delete pRobot;
	pRobot = NULL;

	delete pTreasure;
	pTreasure = NULL;
}

// Public starter member for my private recursive member. This is so I can
// create this object without having to run the recursive program. This would allow
// me to adjust the location of the robot or treasure and run the recursive function
// without having to create a new object.
void Grid::RobotSearch()
{
	pRobotSearch(pRobot->getPosX(), pRobot->getPosY(), "");
}

// Robot Recursion!
void Grid::pRobotSearch(int x, int y, std::string path)
{
	// Check to see if this position matches the treasure
	if (pCheckCollision(x, y, pTreasure))
	{
		// Only the paths that lead to the treasure will
		// Be recorded
		pPaths.push_back(path);
		return;
	}
	
	// Because the robot is able to "see" the treasure, we can
	// avoid unessicary recursive calls if the robot detects that
	// he has to head to one of the cardinal directions to get to
	// the treasure

	// The first conditions in the if statement is to contain the algorithm
	// to a pGridSize x pGridSize area. The second condition is so that the robot does
	// not move in a direction opposite to where the treasure is.
	if ((y + NORTH) <= pGridSize && (pTreasure->getPosY() > y))
	{
		pRobotSearch(x, y + NORTH, path + "N");
	}
	if ((y + SOUTH) >= -pGridSize && pTreasure->getPosY() < y)
	{
		pRobotSearch(x, y + SOUTH, path + "S");
	}
	if ((x + EAST) <= pGridSize && pTreasure->getPosX() > x)
	{
		pRobotSearch(x + EAST, y, path + "E");
	}
	if ((x + WEST) >= -pGridSize && pTreasure->getPosX() < x)
	{
		pRobotSearch(x + WEST, y, path + "W");
	}
}

// Checks to see if the current location is the same as the location
// the object that we are checking. Typically, I would check for two
// entity collisions, but due to the fact that I do not want to pass
// a robot entity to every recursive call, this will suffice.
bool Grid::pCheckCollision(int x, int y, const Entity *entity)
{
	if (x == entity->getPosX())
	{
		if (y == entity->getPosY())
		{
			return true;
		}
	}

	return false;
}

// Override the << operator to print out the list of moves to the console
std::ostream& operator<<(std::ostream &os, const Grid &grid)
{
	
	os << "Number of Paths: " << grid.pPaths.size() << std::endl;

	for (int i = 0; i < grid.pPaths.size(); i++)
	{
		os << grid.pPaths[i] << std::endl;
	}

	return os;
}