#pragma once

#include <memory>

class Pos;

using PosPtr = std::shared_ptr<Pos>;

class Pos
{
	int x;
	int y;
public:
	Pos();
	~Pos();

	bool const operator==(Pos& other);

	int const getX();
	int const getY();

	double const getDistance(Pos& other);
	double const getDistance(int anx, int any);

};

