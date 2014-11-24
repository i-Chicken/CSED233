#include "stunlaser.h"


StunLaser::StunLaser(Team t, Point p, Direction d): Laser(t, p, d){};

bool StunLaser::rotateUnit(Direction){
	if(team == PURPLE)
		direction == DOWN ? direction = LEFT : direction = DOWN;
	else
		direction == UP ?direction = RIGHT : direction = UP;
	return true;
}
