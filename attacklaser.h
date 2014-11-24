#ifndef ATTACKLASER_H
#define ATTACKLASER_H

#include "laser.h"


class AttackLaser : public Laser{
public:
	AttackLaser(Team, Point, Direction);
	bool rotateUnit(Direction);
};

#endif