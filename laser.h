#ifndef LASER_H
#define LASER_H

#include "unit.h"

class Laser: public Unit{
public:
	Laser(Direction, UnitType, Team, int, int);
	Direction getDirection();
protected:
	Direction direction;
};

#endif
