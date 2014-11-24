#include "splitmirror.h"


SplitMirror::SplitMirror(Team t, Point p, int s, Direction d): Mirror(t, p, s, d){};

bool SplitMirror::rotateUnit(Direction d){
	switch (d){
	case LEFT:
		switch(direction){
		case LEFT:	direction = DOWN;			break;
		case DOWN:	direction = RIGHT;			break;
		case RIGHT:	direction = UP;			break;
		case UP:	direction = LEFT;			break;
		}
		break;
	case RIGHT:
		switch(direction){
		case LEFT:	direction = UP;			break;
		case UP:	direction = RIGHT;			break;
		case RIGHT:	direction = DOWN;			break;
		case DOWN:	direction = LEFT;			break;
		}
		break;
	}
	return true;
}

int SplitMirror::beamUnit(Direction& d, UnitType u, int round){
	Direction temp = d;
	switch (d){
	case LEFT:
		if (direction == DOWN)	d = DOWN;
		else if (direction == RIGHT)	d = UP;
		break;
	case DOWN:
		if (direction == RIGHT)	d = RIGHT;
		else if (direction == UP)		d = LEFT;
		break;
	case RIGHT:
		if (direction == UP)		d = UP;
		else if (direction == LEFT)		d = DOWN;
		break;
	case UP:
		if (direction == LEFT)		d = LEFT;
		else if (direction == DOWN)		d = RIGHT;
		break;
	}	// beam reflection
	if (temp == d){	// temp == original direction
		d = DNULL;
		if (u == ATTACK){
			cout << "[System] SplitMirror (" << (char)('A' + point.getX()) << " " << point.getY() + 1 << ") is Destroyed" << endl;
			setPos(Point(-1, -1));
			return 1;
		}	// tri destroy
		else{
			stunUnit(round);
			cout << "[System] Player " << (team == PURPLE ? 1 : 2) << "'s Unit at (" << (char)('A' + point.getX()) << " " << point.getY() + 1 << ") is in stun." << endl;
			return 0;
		}	// tri stun

	}
	return 0;
}

bool SplitMirror::moveUnit(Point p, Unit* u){
	if (u != NULL)	return false;
	if ((p.getX() - point.getX())*(p.getX() - point.getX()) > 1 || (p.getY() - point.getY())*(p.getY() - point.getY()) > 1)	return false;
	if ((p.getX() == 1 && p.getY() == 0) || (p.getX() == 0 && p.getY() == 1))	return false;
	if ((p.getX() == 7 && p.getY() == 8) || (p.getX() == 8 && p.getY() == 7))	return false;
	if ((p.getX() == 0 && p.getY() == 7) || (p.getX() == 1 && p.getY() == 8))	return false;
	if ((p.getX() == 7 && p.getY() == 0) || (p.getX() == 8 && p.getY() == 1))	return false;	// laser adjacent false
	point = p;		// move unit to p
	return true;
}