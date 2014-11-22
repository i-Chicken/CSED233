#include "laser.h"


Laser::Laser(Direction d, UnitType u, Team t, int r, int c): Unit(u, t, r, c){
	direction = d;
}

Direction Laser::getDirection(){	return direction;	}
