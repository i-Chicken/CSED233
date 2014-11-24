#ifndef KING_H
#define KING_H
#include "unit.h"

class King : public Unit{
public:
	King(Team, Point, int);
	bool moveUnit(Point, Unit*);
	int beamUnit(Direction&, UnitType, int);
	bool rotateUnit(Direction);
	Direction getDirection();		// get Direction
};

#endif
