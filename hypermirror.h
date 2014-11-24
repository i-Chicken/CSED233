#ifndef HYPERMIRROR_H
#define HYPERMIRROR_H

#include "mirror.h"


class HyperMirror:public Mirror{
public:
	HyperMirror(Team, Point, Direction);	//UP, LEFT
	bool rotateUnit(Direction);
	int beamUnit(Direction&, UnitType, int);
	bool moveUnit(Point, Unit*);
};

#endif

