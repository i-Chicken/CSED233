#include "stunlaser.h"


StunLaser::StunLaser(Direction d, Team t, int r, int c): Laser(d, STUN, t, r, c){};

void StunLaser::setRotation(){
	if(team == PURPLE)
		direction == DOWN ? direction = LEFT : direction = DOWN;
	else
		direction == UP ?direction = RIGHT : direction = UP;
}
