#include "blockmirror.h"


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

int BlockMirror::beamUnit(Direction& d, UnitType u, int round){
	if(direction == RIGHT && d == LEFT)	d=DNULL;
	else if(direction == UP && d == DOWN)	d=DNULL;
	else if(direction == LEFT && d == RIGHT)	d=DNULL;
	else if(direction == DOWN && d == UP)	d=DNULL;	// beam blocking
	else if(u==ATTACK){
		removeUnit();
		cout << "[System] BlockMirror at (" << (char)('A'+row) << " " << col+1 << ") is Destroyed" << endl;
		d=DNULL;
	}	//block destroy
	else{
		cout << "[System] Player " << (team == PURPLE ? 1:2) << "'s Unit at (" << (char)('A'+row) << " " << col+1 << ") is in stun." << endl;
		stunUnit(round);
		d=DNULL;
	}
	return 0;
}
