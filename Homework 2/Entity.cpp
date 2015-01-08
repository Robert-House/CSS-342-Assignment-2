#include "Entity.h"

Entity::Entity(int x, int y)
{
	pPosition.x = x;
	pPosition.y = y;
}

Entity::~Entity() {};

int Entity::getPosX() const
{
	return pPosition.x;
}

int Entity::getPosY() const
{
	return pPosition.y;
}

bool Entity::MoveTo(int x, int y)
{
	pPosition.x = x;
	pPosition.y = y;

	return true;
}


// Left over members for another time. Maybe a simple game where I use
// the recursive movement algorithm to contol AI movement. Would call these to
// update the position after randomly selecting one of the move sets.
bool Entity::MoveUp()
{
	pPosition.y += 1;
	return true;
}

bool Entity::MoveDown()
{
	pPosition.y -= 1;
	return true;
}

bool Entity::MoveLeft()
{
	pPosition.x -= 1;
	return true;
}

bool Entity::MoveRight()
{
	pPosition.x += 1;
	return true;
}