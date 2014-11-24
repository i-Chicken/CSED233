#include "king.h"

King::King(Team t, Point p, int s): Unit(t, p, s){};

bool King::moveUnit(Point p, Unit* u){
	if (u != NULL)	return false;
	if ((p.getX() - point.getX())*(p.getX() - point.getX()) > 1 || (p.getY() - point.getY())*(p.getY() - point.getY()) > 1)	return false;
	if ((p.getX() == 1 && p.getY() == 0) || (p.getX() == 0 && p.getY() == 1))	return false;
	if ((p.getX() == 7 && p.getY() == 8) || (p.getX() == 8 && p.getY() == 7))	return false;
	if ((p.getX() == 0 && p.getY() == 7) || (p.getX() == 1 && p.getY() == 8))	return false;
	if ((p.getX() == 7 && p.getY() == 0) || (p.getX() == 8 && p.getY() == 1))	return false;	// laser adjacent false
	point = p;		// move unit to p
	return true;
}

bool King::rotateUnit(Direction){
	return false;		// king cannot move
}

int King::beamUnit(Direction& d, UnitType u, int round){
	d=DNULL;
	if(u == ATTACK){
		cout << "[System] King of Player " << (team == PURPLE ? 1:2) << "is defeated" << endl;
		return (team == PURPLE ? 1:2);
	}
	else{
		cout << "[System] Player " << (team == PURPLE ? 1 : 2) << "'s Unit at (" << (char)('A' + point.getX()) << " " << point.getY() +1 << ") is in stun." << endl;
		stunUnit(round);
		return 0;
	}
}

Direction King::getDirection(){
	return DNULL;
}

