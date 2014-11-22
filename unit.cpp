#include "unit.h"

Unit::Unit(UnitType u, Team t, int r, int c){
	unittype=u;
	team=t;
	row=r;
	col=c;
	stun=-1;
}

Team Unit::getTeam(){	return team;	}
UnitType Unit::getUnitType(){	return unittype;	}

void Unit::moveUnit(int r, int c){
	row=r;
	col=c;
}

void Unit::stunUnit(int s){	stun=s;	}
bool Unit::isStun(int round){
	if(round - stun < 2)
		return true;
	return false;
}
