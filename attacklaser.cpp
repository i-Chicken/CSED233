#include "attacklaser.h"


AttackLaser::AttackLaser(Team t, Point p, Direction d): Laser(t, p, d){};

bool AttackLaser::rotateUnit(Direction d){
	if(team == PURPLE)
		direction == DOWN ? direction = RIGHT : direction = DOWN;
	else
		direction == UP ? direction = LEFT : direction = UP;
	return true;
}
