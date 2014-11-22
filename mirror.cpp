#include "mirror.h"


Mirror::Mirror(Direction d, UnitType u, Team t, int r, int c): Unit(u, t, r, c){
	direction = d;
}

Direction Mirror::getDirection(){	return direction;	}
