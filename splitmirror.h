#ifndef SPLITMIRROR_H
#define SPLITMIRROR_H

#include "mirror.h"


class SplitMirror : public Mirror{
public:
	SplitMirror(Team, Point, int, Direction);
	bool rotateUnit(Direction);
	int beamUnit(Direction&, UnitType, int);
	bool moveUnit(Point, Unit*);
};

#endif

