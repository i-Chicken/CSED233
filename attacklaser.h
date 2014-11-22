#ifndef ATTACKLASER_H
#define ATTACKLASER_H

#include "laser.h"


class AttackLaser : public Laser{
public:
	AttackLaser(Direction, Team, int, int);
	void setRotation();
};

#endif
