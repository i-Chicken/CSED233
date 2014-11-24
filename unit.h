#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "global.h"

using namespace std;

class Unit{
public:
	Unit(Team, Point, int);	// team, row, col, stun
	Team getTeam();
	Point getPos();
	virtual	Direction getDirection()=0;		// get Direction
	virtual bool moveUnit(Point, Unit*)=0;	// 0 - unable move, 1 - possible
	virtual int beamUnit(Direction&, UnitType, int)=0;	// 0 - Nothing Happened, 1 - Unit Destroyed, 2 - PURPLE king down, 3 - BLUE king down
	virtual bool rotateUnit(Direction) = 0;	// 0 - unable move, 1 - possible
	bool isStun(int);
protected:
	Team team;
	Point point;
	int stun;
	void stunUnit(int);     // Unit stunned by laser(private method)
};

#endif
