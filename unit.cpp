#include "unit.h"

Unit::Unit(Team t, Point p, int s=-1){
	team=t;
	point = p;
	stun=s;
}

Point Unit::getPos(){ return point; }

Team Unit::getTeam(){	return team;	}

void Unit::stunUnit(int s){	stun=s;	}
bool Unit::isStun(int round){
	if(round - stun < 2)
		return true;
	return false;
}

bool Unit::setPos(Point p){
	point = p;
	return true;
}