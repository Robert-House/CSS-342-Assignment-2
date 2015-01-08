//=================================================================
// Entity.h
// Author:	Robert House
// Date:	13 OCT 2014
//
// Simple entity class that holds x/y spatial locations. Has the
// ability to return said positions. Note, this did not have to be a
// seperate object. I made this so it could be reused if there is a 
// similar assignment in the future.
//=================================================================
class Entity
{
	// Internal struct, for something this simple, I guess it
	// doesn't matter all that much.
	struct Position
	{
		int x;
		int y;
	};

public:
	Entity(int x, int y);
	~Entity();

	// Return respective x and y positions
	int getPosX() const;
	int getPosY() const;

	// Move this object to a new location
	bool MoveTo(int x, int y);

	// Leftovers, see .cpp file
	bool MoveUp();
	bool MoveDown();
	bool MoveLeft();
	bool MoveRight();

private:
	Position pPosition;
};