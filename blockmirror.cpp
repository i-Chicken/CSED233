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
