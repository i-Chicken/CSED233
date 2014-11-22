#ifndef HYPERMIRROR_H
#define HYPERMIRROR_H

#include "mirror.h"


class HyperMirror:public Mirror{
public:
	HyperMirror(Direction, Team, int, int);	//UP, LEFT
	void setRotation();
};

#endif
