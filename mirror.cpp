#include "mirror.h"


Mirror::Mirror(Team t, Point p, int s, Direction d): Unit(t, p, s){
	direction = d;
}

Direction Mirror::getDirection(){	return direction;	}
