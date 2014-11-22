#ifndef MIRROR_H
#define MIRROR_H

#include "unit.h"

class Mirror : public Unit{
public:
	Mirror(Direction, UnitType, Team, int, int);
	Direction getDirection();
protected:
	Direction direction;
};

#endif
