#include "laser.h"


Laser::Laser(Direction d, UnitType u, Team t, int r, int c): Unit(u, t, r, c){
	direction = d;
}

Direction Laser::getDirection(){	return direction;	}

bool Laser::moveUnit(int r, int c){
	return false;
}

int Laser::beamUnit(Direction& d, UnitType u, int round){
	d=DNULL;
	return 0;
}
