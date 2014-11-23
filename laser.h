#ifndef LASER_H
#define LASER_H

#include "unit.h"

class Laser: public Unit{
public:
	Direction getDirection();
	bool moveUnit(int, int);
	bool rotateUnit(Direction)=0;
	int beamUnit(Direction&, UnitType, int);
	Laser(Direction, UnitType, Team, int, int);
protected:
	Direction direction;
};

#endif
