#include "stdafx.h"
#include "Pos.h"


Pos::Pos()
{
}


Pos::~Pos()
{
}

bool const Pos::operator==(Pos & other)
{
	if (x == other.x && y == other.y)
	{
		return true;
	}
	return false;
}

int const Pos::getX()
{
	return x;
}

int const Pos::getY()
{
	return y;
}

double const Pos::getDistance(Pos & other)
{
	return getDistance(other.getX(), other.getY());
}

double const Pos::getDistance(int anx, int any)
{
	if (x == anx && y == any);
	return sqrt((x - anx)*(x - anx) + (y - any)*(y - any));
}
