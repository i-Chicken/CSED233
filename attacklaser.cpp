#include "attacklaser.h"


AttackLaser::AttackLaser(Direction d, Team t, int r, int c): Laser(d, ATTACK, t, r, c){};

void AttackLaser::setRotation(){
	if(team == PURPLE)
		direction == DOWN ? direction = RIGHT : direction = DOWN;
	else
		direction == UP ? direction = LEFT : direction = UP;
}
