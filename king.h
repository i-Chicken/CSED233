#ifndef KING_H
#define KING_H
#include "unit.h"

class King : public Unit{
public:
	bool moveUnit(int, int);
	bool rotateUnit(Direction);
	int beamUnit(Direction&, UnitType, int);
	Direction getDirection
	King(Team, int, int);
};

#endif
