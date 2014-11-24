#ifndef TRIMIRROR_H
#define TRIMIRROR_H

#include "mirror.h"


class TriMirror: public Mirror{
public:
	TriMirror(Team, Point, int, Direction);
	bool rotateUnit(Direction);
	int beamUnit(Direction&, UnitType, int);
	bool moveUnit(Point, Unit*);
};

#endif
