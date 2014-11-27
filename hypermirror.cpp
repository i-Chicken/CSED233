#include "hypermirror.h"


HyperMirror::HyperMirror(Team t, Point p, Direction d): Mirror(t, p, -1, d){};

bool HyperMirror::rotateUnit(Direction d){
	direction == UP ? direction = LEFT : direction = UP;
	return true;
}

int HyperMirror::beamUnit(Direction& d, UnitType u, int r){
	switch (d){
	case LEFT:
		direction == UP ? d = DOWN : d = UP;
		break;
	case DOWN:
		direction == UP ? d = LEFT : d = RIGHT;
		break;
	case RIGHT:
		direction == UP ? d = UP : d = DOWN;
		break;
	case UP:
		direction == UP ? d = RIGHT : d = LEFT;
		break;
	}	// beam reflection
	return 0;
}

bool HyperMirror::moveUnit(Point p, Unit* u){
	if ((p.getX() - point.getX())*(p.getX() - point.getX()) > 1 || (p.getY() - point.getY())*(p.getY() - point.getY()) > 1)	return false;
	if ((p.getX() == 0 && p.getY() == 0) || (p.getX() == 0 && p.getY() == 8) || (p.getX() == 8 && p.getY() == 0) || (p.getX() == 8 && p.getY() == 8))	return false;	// laser postion
	if ((p.getX() == 1 && p.getY() == 0) || (p.getX() == 0 && p.getY() == 1))	return false;
	if ((p.getX() == 7 && p.getY() == 8) || (p.getX() == 8 && p.getY() == 7))	return false;
	if ((p.getX() == 0 && p.getY() == 7) || (p.getX() == 1 && p.getY() == 8))	return false;
	if ((p.getX() == 7 && p.getY() == 0) || (p.getX() == 8 && p.getY() == 1))	return false;	// laser adjacent false
	if(u != NULL)
		u->moveUnit(point, NULL);
	point = p;		// move unit to p
	return true;

}
