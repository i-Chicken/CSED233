#ifndef STUNLASER_H
#define STUNLASER_H

#include "laser.h"

class StunLaser : public Laser{
public:
	StunLaser(Team, Point, Direction);
	bool rotateUnit(Direction);
};


#endif
