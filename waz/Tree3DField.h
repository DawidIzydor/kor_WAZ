#pragma once

#include <memory>
#include <limits>
#include "Pos.h"

class Tree3DField;

using TreePtr = std::shared_ptr<Tree3DField>;

class Tree3DField
	: public std::enable_shared_from_this<Tree3DField>
{
	PosPtr position;

	TreePtr left;
	TreePtr right;

	TreePtr parent;

	double leftDist = std::numeric_limits<double>::max();
	double rightDist = std::numeric_limits<double>::max();

	TreePtr& getClosestTo(int x, int y);

public:
	Tree3DField();
	~Tree3DField();

	bool Add(TreePtr& another);
	bool Search(TreePtr& search);
	bool Search(int x, int y);

	TreePtr&& Find(TreePtr& find);
	TreePtr&& Find(int x, int y);

	TreePtr&& getParent();

	PosPtr& getPos();
};

