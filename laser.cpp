#include "laser.h"


Laser::Laser(Team t, Point p, Direction d): Unit(t, p, -1){
	direction = d;
}

Direction Laser::getDirection(){	return direction;	}

bool Laser::moveUnit(Point p, Unit* u){
	return false;
}

int Laser::beamUnit(Direction& d, UnitType u, int round){
	d=DNULL;
	return 0;
}