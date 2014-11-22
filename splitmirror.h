#ifndef SPLITMIRROR_H
#define SPLITMIRROR_H

#include "mirror.h"


class SplitMirror : public Mirror{
public:
	SplitMirror(Direction, Team, int, int);
	void setRotation(Direction d);
};

#endif
