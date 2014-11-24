#ifndef LASER_H
#define LASER_H

#include "unit.h"

class Laser: public Unit{
public:
	Laser(Team, Point, Direction);
	Direction getDirection();
	bool moveUnit(Point, Unit*);
	int beamUnit(Direction&, UnitType, int);
	virtual bool rotateUnit(Direction) = 0;
protected:
	Direction direction;
};

#endif