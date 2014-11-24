#include "blockmirror.h"


BlockMirror::BlockMirror(Team t, Point p, int s, Direction d): Mirror(t, p, s, d){};

bool BlockMirror::rotateUnit(Direction d){
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

int BlockMirror::beamUnit(Direction& d, UnitType u, int round){
	if(direction == RIGHT && d == LEFT)	d=DNULL;
	else if(direction == UP && d == DOWN)	d=DNULL;
	else if(direction == LEFT && d == RIGHT)	d=DNULL;
	else if(direction == DOWN && d == UP)	d=DNULL;	// beam blocking
	else if(u==ATTACK){
		cout << "[System] BlockMirror at (" << (char)('A'+point.getX()) << " " << point.getY()+1 << ") is Destroyed" << endl;
		moveUnit(Point(-1, -1), NULL);
		d=DNULL;
		return 1;
	}	//block destroy
	else{
		cout << "[System] Player " << (team == PURPLE ? 1:2) << "'s Unit at (" << (char)('A'+point.getX()) << " " << point.getY()+1 << ") is in stun." << endl;
		stunUnit(round);
		d=DNULL;
	}
	return 0;
}

bool BlockMirror::moveUnit(Point p, Unit* u){
	if (u != NULL)	return false;
	if ((p.getX() - point.getX())*(p.getX() - point.getX()) > 1 || (p.getY() - point.getY())*(p.getY() - point.getY()) > 1)	return false;
	if ((p.getX() == 1 && p.getY() == 0) || (p.getX() == 0 && p.getY() == 1))	return false;
	if ((p.getX() == 7 && p.getY() == 8) || (p.getX() == 8 && p.getY() == 7))	return false;
	if ((p.getX() == 0 && p.getY() == 7) || (p.getX() == 1 && p.getY() == 8))	return false;
	if ((p.getX() == 7 && p.getY() == 0) || (p.getX() == 8 && p.getY() == 1))	return false;	// laser adjacent false
	point = p;		// move unit to p
	return true;
}