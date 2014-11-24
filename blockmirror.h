#ifndef BLOCKMIRROR_H
#define BLOCKMIRROR_H

#include "mirror.h"


class BlockMirror: public Mirror{
public:
	BlockMirror(Team, Point, int, Direction);
	int beamUnit(Direction&, UnitType, int);
	bool rotateUnit(Direction);
	bool moveUnit(Point, Unit*);
};

#endif
