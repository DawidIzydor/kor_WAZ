#include "stdafx.h"
#include "Tree3DField.h"


// returns closest element to X, Y
// to refactorize with Find()
// TO DO 
TreePtr & Tree3DField::getClosestTo(int x, int y)
{
	if (position->getX() == x && position->getY() == y)
	{
		return shared_from_this();
	}

	if (left == nullptr && right == nullptr)
	{
		return shared_from_this();
	}

	double ldistance = (left == nullptr ? std::numeric_limits<double>::max() : left->getPos()->getDistance(x, y));

	double rdistance = (right == nullptr ? std::numeric_limits<double>::max() : right->getPos()->getDistance(x, y));

	if (ldistance < rdistance)
	{
		return left->getClosestTo(x, y);
	}
	else {
		return right->getClosestTo(x, y);
	}
}

Tree3DField::Tree3DField()
{
}


Tree3DField::~Tree3DField()
{
}

bool Tree3DField::Add(TreePtr& another)
{
	
}

bool Tree3DField::Search(TreePtr& search)
{
	if (search == nullptr)
	{
		return true;
	}

	return Search(search->getPos()->getX(), search->getPos()->getY());
}

bool Tree3DField::Search(int x, int y)
{

	if (Find(x, y) != nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}


TreePtr && Tree3DField::Find(TreePtr& find)
{
	return Find(find->getPos()->getX(), find->getPos()->getY());
}

TreePtr && Tree3DField::Find(int x, int y)
{
	if (position->getX() == x && position->getY() == y)
	{
		return shared_from_this();
	}

	if (left == nullptr && right == nullptr)
	{
		return nullptr;
	}

	double ldistance = (left == nullptr ? std::numeric_limits<double>::max() : left->getPos()->getDistance(x, y));

	double rdistance = (right == nullptr ? std::numeric_limits<double>::max() : right->getPos()->getDistance(x, y));

	if (ldistance < rdistance)
	{
		return left->Find(x, y);
	}
	else {
		return right->Find(x, y);
	}
}

TreePtr && Tree3DField::getParent()
{
	return std::move(parent);
}

PosPtr & Tree3DField::getPos()
{
	return position;
}
