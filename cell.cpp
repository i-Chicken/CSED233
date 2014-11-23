#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(int r, int c){
	row=r;
	col=c;
	unit=NULL;
	accessible=true;
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
	return DNULL;
}
//////////////////////////// getMethod


void Cell::removeUnit(){
	delete unit;
	unit=NULL;
	accessible=true;
}
/////////////////////////////// remove

void Cell::setCell(Unit* o, bool a){
	accessible=a;
	unit=o;
}
////////////////////////////// setCell


void Cell::setUnitDir(Direction d){
	unit->rotateUnit(d);
}


bool Cell::movableFrom(UnitType u, int r, int c){
	if( (row-r)*(row-r) > 1 || (col-c)*(col-c) > 1)	return false;
	switch(u){
	case HYPER:
		if(accessible == false && unit != NULL)	return false;
		if(getUnitType() == STUN || getUnitType() == ATTACK)	return false;
		break;
	default:
		if(accessible == false)	return false;
		break;
	}
	return true;
}

void Cell::moveTo(Cell* target){
	if(getUnitType() == HYPER){
		swapWith(target);
		return;
	}
	target->setCell(unit, false);
	unit=NULL;
	accessible=true;
}


void Cell::swapWith(Cell* target){
	Unit* temp=unit;
	target->moveTo(this);	// Unit Moves : target -> this
	target->setCell(temp, false);	// Unit Moves : this -> target
}

bool Cell::isUnitStun(int r){    return unit->isStun(r); }

int Cell::beamCurCell(Direction& d, UnitType u, int round){
	Direction temp=d;
	if(unit != NULL)
		return	unit->beamUnit(d,u,round);

	switch(getUnitType()){
	case TRI:
		switch(d){
		case LEFT:
			if(getUnitDir() == DOWN)	d=DOWN;
			else if(getUnitDir() == RIGHT)	d=UP;
			break;
		case DOWN:
			if(getUnitDir() == RIGHT)	d=RIGHT;
			else if(getUnitDir() == UP)		d=LEFT;
			break;
		case RIGHT:
			if(getUnitDir() == UP)		d=UP;
			else if(getUnitDir() == LEFT)		d=DOWN;
			break;
		case UP:
			if(getUnitDir() == LEFT)		d=LEFT;
			else if(getUnitDir() == DOWN)		d=RIGHT;
			break;
		}	// beam reflection
		if(temp == d){	// temp == original direction
			if(u == ATTACK){
				removeUnit();
				cout << "[System] TriMirror (" << (char)('A'+row) << " " << col+1 << ") is Destroyed" << endl;
			}	// tri destroy
			else{
				unit->stunUnit(round);
				cout << "[System] Player " << (getUnitTeam() == PURPLE ? 1:2) << "'s Unit at (" << (char)('A'+row) << " " << col+1 << ") is in stun." << endl;
			}	// tri stun
            d=DNULL;
		}
		return 0;
	case SPLIT:
		switch(d){
		case LEFT:
			if(getUnitDir() == DOWN)	d=DOWN;
			else if(getUnitDir() == RIGHT)	d=UP;
			break;
		case DOWN:
			if(getUnitDir() == RIGHT)	d=RIGHT;
			else if(getUnitDir() == UP)		d=LEFT;
			break;
		case RIGHT:
			if(getUnitDir() == UP)		d=UP;
			else if(getUnitDir() == LEFT)		d=DOWN;
			break;
		case UP:
			if(getUnitDir() == LEFT)		d=LEFT;
			else if(getUnitDir() == DOWN)		d=RIGHT;
			break;
		}	// beam reflection
		if(temp == d){	// temp == original direction
			if(u == ATTACK){
				removeUnit();
				cout << "[System] SplitMirror (" << (char)('A'+row) << " " << col+1 << ") is Destroyed" << endl;
			}	// tri destroy
			else{
				unit->stunUnit(round);
				cout << "[System] Player " << (getUnitTeam() == PURPLE ? 1:2) << "'s Unit at (" << (char)('A'+row) << " " << col+1 << ") is in stun." << endl;
			}	// tri stun
			d=DNULL;
		}
		return 0;
	case HYPER:
		switch(d){
		case LEFT:
			getUnitDir() == UP ? d=DOWN : d=UP;
			break;
		case DOWN:
			getUnitDir() == UP ? d=LEFT : d=RIGHT;
			break;
		case RIGHT:
			getUnitDir() == UP ? d=UP : d=DOWN;
			break;
		case UP:
			getUnitDir() == UP ? d=RIGHT : d=LEFT;
			break;
		}	// beam reflection
		return 0;
    }
    return 0;
}
