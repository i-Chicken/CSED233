#include "unit.h"

Unit::Unit(UnitType u, Team t, int r, int c){
	unittype=u;
	team=t;
	row=r;
	col=c;
	stun=-1;
}

Team Unit::getTeam(){	return team;	}
UnitType Unit::getUnitType(){	return unittype;	}

void Unit::moveUnit(int r, int c){
	row=r;
	col=c;
}

void Unit::stunUnit(int s){	stun=s;	}
bool Unit::isStun(int round){
	if(round - stun < 2)
		return true;
	return false;
}

King::King(Team t, int r, int c): Unit(KING, t, r, c){}; 

Laser::Laser(Direction d, UnitType u, Team t, int r, int c): Unit(u, t, r, c){
	direction = d;
}

Direction Laser::getDirection(){	return direction;	}

AttackLaser::AttackLaser(Direction d, Team t, int r, int c): Laser(d, ATTACK, t, r, c){};

void AttackLaser::setRotation(){
	if(team == PURPLE)
		direction == DOWN ? direction = RIGHT : direction = DOWN;
	else
		direction == UP ? direction = LEFT : direction = UP;
}

StunLaser::StunLaser(Direction d, Team t, int r, int c): Laser(d, STUN, t, r, c){};

void StunLaser::setRotation(){
	if(team == PURPLE)
		direction == DOWN ? direction = LEFT : direction = DOWN;
	else
		direction == UP ?direction = RIGHT : direction = UP;
}

Mirror::Mirror(Direction d, UnitType u, Team t, int r, int c): Unit(u, t, r, c){
	direction = d;
}

Direction Mirror::getDirection(){	return direction;	}

BlockMirror::BlockMirror(Direction d, Team t, int r, int c): Mirror(d, BLOCK, t, r, c){};

void BlockMirror::setRotation(Direction d){
	switch (d){
	case LEFT:
		switch(direction){
		case LEFT:	direction = DOWN;			break;
		case DOWN:	direction = RIGHT;			break;
		case RIGHT:	direction = UP;			break;
		case UP:	direction = LEFT;			break;
		}
		break;
	case RIGHT:
		switch(direction){
		case LEFT:	direction = UP;			break;
		case UP:	direction = RIGHT;			break;
		case RIGHT:	direction = DOWN;			break;
		case DOWN:	direction = LEFT;			break;
		}
		break;
	}
}

TriMirror::TriMirror(Direction d, Team t, int r, int c): Mirror(d, TRI, t, r, c){};

void TriMirror::setRotation(Direction d){
	switch (d){
	case LEFT:
		switch(direction){
		case LEFT:	direction = DOWN;			break;
		case DOWN:	direction = RIGHT;			break;
		case RIGHT:	direction = UP;			break;
		case UP:	direction = LEFT;			break;
		}
		break;
	case RIGHT:
		switch(direction){
		case LEFT:	direction = UP;			break;
		case UP:	direction = RIGHT;			break;
		case RIGHT:	direction = DOWN;			break;
		case DOWN:	direction = LEFT;			break;
		}
		break;
	}
}


SplitMirror::SplitMirror(Direction d, Team t, int r, int c): Mirror(d, SPLIT, t, r, c){};


void SplitMirror::setRotation(Direction d){
	switch (d){
	case LEFT:
		switch(direction){
		case LEFT:	direction = DOWN;			break;
		case DOWN:	direction = RIGHT;			break;
		case RIGHT:	direction = UP;			break;
		case UP:	direction = LEFT;			break;
		}
		break;
	case RIGHT:
		switch(direction){
		case LEFT:	direction = UP;			break;
		case UP:	direction = RIGHT;			break;
		case RIGHT:	direction = DOWN;			break;
		case DOWN:	direction = LEFT;			break;
		}
		break;
	}
}

HyperMirror::HyperMirror(Direction d, Team t, int r, int c): Mirror(d, HYPER, t, r, c){};

void HyperMirror::setRotation(){
	direction == UP ? direction = LEFT : direction = UP;
}
