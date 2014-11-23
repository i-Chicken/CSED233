#ifndef BLOCKMIRROR_H
#define BLOCKMIRROR_H

#include "mirror.h"


class BlockMirror: public Mirror{
public:
	BlockMirror(Direction, Team, int, int);
	int beamUnit(Direction&, UnitType, int);
	void setRotation(Direction d);
};

#endif
