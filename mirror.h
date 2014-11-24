#ifndef MIRROR_H
#define MIRROR_H

#include "unit.h"

class Mirror : public Unit{
public:
	Mirror(Team, Point, int, Direction);
	Direction getDirection();
	virtual bool rotateUnit(Direction) = 0;
	virtual int beamUnit(Direction&, UnitType, int) = 0;
	virtual bool moveUnit(Point, Unit*) = 0;
protected:
	Direction direction;
};

#endif