#ifndef STUNLASER_H
#define STUNLASER_H

#include "laser.h"

class StunLaser : public Laser{
public:
	StunLaser(Direction, Team, int, int);
	void setRotation();
};


#endif
