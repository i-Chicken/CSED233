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
	Cell(int, int);
	~Cell();
	void removeUnit();
	void setCell(Unit*, bool);
	void setUnitDir(Direction);
	bool movableFrom(UnitType, int, int);
	void moveTo(Cell*);
	void swapWith(Cell*);
	Team getUnitTeam();
	Direction getUnitDir();
	UnitType getUnitType();
	bool isUnitStun(int);
    int beamCurCell(Direction&, UnitType, int);
private:
	int row, col;
	Unit* unit;
	bool accessible;
};

#endif
