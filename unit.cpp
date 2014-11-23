#include "unit.h"

Unit::Unit(Team t, int r, int c, int s){
	team=t;
	row=r;
	col=c;
	stun=s;
}

Team Unit::getTeam(){	return team;	}


void Unit::stunUnit(int s){	stun=s;	}
bool Unit::isStun(int round){
	if(round - stun < 2)
		return true;
	return false;
}
