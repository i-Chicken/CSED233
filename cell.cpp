#include <iostream>
#include "cell.h"
#include <typeinfo>

using namespace std;

Cell::Cell(Point p){
	point = p;
	unit=NULL;
}
/// Cell Constructor

Cell::~Cell(){
	delete unit;
}
////////////////////////// Cell Deconstructor

Team Cell::getUnitTeam(){
	if(unit == NULL)	return TNULL;
	return unit->getTeam();
}
Direction Cell::getUnitDir(){
	if (unit == NULL)	return DNULL;
	return unit->getDirection();
}
UnitType Cell::getUnitType(){
	if (unit == NULL)	return UNULL;
	if (dynamic_cast<King *>(unit) != NULL)	return KING;
	if (dynamic_cast<AttackLaser *>(unit) != NULL)	return ATTACK;
	if (dynamic_cast<StunLaser *>(unit) != NULL)	return STUN;
	if (dynamic_cast<BlockMirror *>(unit) != NULL)	return BLOCK;
	if (dynamic_cast<TriMirror *>(unit) != NULL)	return TRI;
	if (dynamic_cast<SplitMirror *>(unit) != NULL)	return SPLIT;
	if (dynamic_cast<HyperMirror *>(unit) != NULL)	return HYPER;
	return UNULL;
}
//////////////////////////// getMethod

void Cell::removeUnit(){
	unit=NULL;
}

bool Cell::moveTo(Point p, Unit* u){
	if (unit == NULL)	return false;
	unit->moveUnit(p, u);
	return true;
}
void Cell::setCell(Unit* o){
	unit=o;
}

void Cell::setUnitDir(Direction d){
	unit->rotateUnit(d);
}

bool Cell::isUnitStun(int r){    return unit->isStun(r); }

int Cell::beamCurCell(Direction& d, UnitType u, int round){
	Direction temp=d;
	int result=0;
	if (unit != NULL){
		result = unit->beamUnit(d, u, round);
		if (result != 0)
			unit = NULL;
	}
	return result;
}
