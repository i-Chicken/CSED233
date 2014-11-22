#include "hypermirror.h"


HyperMirror::HyperMirror(Direction d, Team t, int r, int c): Mirror(d, HYPER, t, r, c){};

void HyperMirror::setRotation(){
	direction == UP ? direction = LEFT : direction = UP;
}
