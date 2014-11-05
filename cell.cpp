#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(int r, int c){
	row=r;
	col=c;
	unit=NULL;
	unittype=UNULL;
	accessible=true;
}
/// Cell Constructor

Cell::~Cell(){
	delete unit;
}
////////////////////////// Cell Deconstructor

Team Cell::getUnitTeam(){
	switch(unittype){
	case UNULL:
		return TNULL;
	default:
		return unit->getTeam();
	}	
}
Direction Cell::getUnitDir(){
	switch(unittype){
	case KING:		return DNULL;
	case ATTACK:
	case STUN:
		return ((Laser*)unit)->getDirection();
	case BLOCK:
	case TRI:
	case SPLIT:
	case HYPER:
		return ((Mirror*)unit)->getDirection();
	}	
	return DNULL;
}

UnitType Cell::getUnitType(){
	if(unit == NULL)
		return UNULL;
	return unit->getUnitType();
}
//////////////////////////// getMethod


void Cell::removeUnit(){
	unittype=UNULL;
	delete unit;
	unit=NULL;
	accessible=true;
}
/////////////////////////////// remove

void Cell::setCell(UnitType u, Unit* o, bool a){
	unittype=u;
	accessible=a;
	unit=o;
}
////////////////////////////// setCell


void Cell::setUnitDir(Direction d){
	switch(unittype){
	case ATTACK:
	case STUN:
		((Laser*)unit)->setRotation();
		break;
	case BLOCK:
		((BlockMirror*)unit)->setRotation(d);
		break;
	case TRI:
		((TriMirror*)unit)->setRotation(d);
		break;
	case SPLIT:
		((SplitMirror*)unit)->setRotation(d);
		break;
	case HYPER:
		((HyperMirror*)unit)->setRotation();
		break;
	}
}


bool Cell::movableTo(UnitType u, int r, int c){
	if( (row-r)*(row-r) > 1 || (col-c)*(col-c) > 1)	return false;
	switch(u){
	case HYPER:
		if(accessible == false && unit != NULL)	return false;
		if(unittype == STUN || unittype == ATTACK)	return false;
		break;
	default:
		if(accessible == false)	return false;
		break;
	}
	return true;
}

void Cell::moveTo(Cell* target){
	target->setCell(unittype, unit, false);
	unit=NULL;
	unittype=UNULL;
	accessible=true;
}


void Cell::swapWith(Cell* target){
	Unit* temp=unit;
	target->moveTo(this);	// Unit Moves : target -> this
	target->setCell(temp->getUnitType(), temp, false);	// Unit Moves : this -> target
}
