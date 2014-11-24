#ifndef CELL_H
#define CELL_H
#include "king.h"
#include "laser.h"
#include "attacklaser.h"
#include "stunlaser.h"
#include "mirror.h"
#include "blockmirror.h"
#include "trimirror.h"
#include "hypermirror.h"
#include "splitmirror.h"

class Cell{
public:
	Cell(Point);
	~Cell();
	void removeUnit();
	void setCell(Unit*);
	void setUnitDir(Direction);
	bool moveTo(Point, Unit*);
	Team getUnitTeam();
	UnitType getUnitType();
	Direction getUnitDir();
	bool isUnitStun(int);
    int beamCurCell(Direction&, UnitType, int);
private:
	Point point;
	Unit* unit;
};

#endif
