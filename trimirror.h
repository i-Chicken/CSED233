#ifndef TRIMIRROR_H
#define TRIMIRROR_H

#include "mirror.h"


class TriMirror: public Mirror{
public:
	TriMirror(Direction, Team, int, int);
	void setRotation(Direction d);
};

#endif
