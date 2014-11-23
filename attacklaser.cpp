#include "attacklaser.h"


AttackLaser::AttackLaser(Direction d, Team t, int r, int c): Laser(d, ATTACK, t, r, c){};

bool AttackLaser::rotateUnit(Direction d){
	if(team == PURPLE)
		direction == DOWN ? direction = RIGHT : direction = DOWN;
	else
		direction == UP ? direction = LEFT : direction = UP;
	return true;
}
