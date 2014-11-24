#include "unit.h"

Unit::Unit(Team t, Point p, int s=-1){
	team=t;
	point = p;
	stun=s;
}

Point Unit::getPos(){ return point; }

Team Unit::getTeam(){	return team;	}

void Unit::stunUnit(int s){	stun=s;	}
bool Unit::isStun(int round){
	if(round - stun < 2)
		return true;
	return false;
}


ofstream& operator<<(ofstream& os, Unit* unit){
	if (dynamic_cast<AttackLaser*>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'A' << -1 << 'U' << (char)('A'+point->getX()) << (char)('1'+point->getY());
			break;
		case DOWN:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'A' << -1 << 'D' << (char)('A'+point->getX()) << (char)('1'+point->getY());
			break;
		case RIGHT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'A' << -1 << 'R' << (char)('A'+point->getX()) << (char)('1'+point->getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'A' << -1 << 'L' << (char)('A'+point->getX()) << (char)('1'+point->getY());
			break;
		}
	}/*
	if (dynamic_cast<StunLaser*>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'S' << -1 << 'U' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case DOWN:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'S' << -1 << 'D' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case RIGHT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'S' << -1 << 'R' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'S' << -1 << 'L' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		}
	}
	if (dynamic_cast<BlockMirror>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << stun << 'U' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case DOWN:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << stun << 'D' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case RIGHT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << stun << 'R' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << stun << 'L' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		}
	}
	
	if (dynamic_cast<TriMirror>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'T' << stun << 'U' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case DOWN:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'T' << stun << 'D' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case RIGHT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'T' << stun << 'R' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'T' << stun << 'L' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		}
	}
	if (dynamic_cast<SplitMirror>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'P' << stun << 'U' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case DOWN:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'P' << stun << 'D' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case RIGHT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'P' << stun << 'R' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'P' << stun << 'L' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		}
	}
	if (dynamic_cast<HyperMirror>(unit) != NULL){
		switch(getDirection()){
		case UP:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << -1 << 'U' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		case LEFT:
			os << ((team == PURPLE) ? 'P' ? 'B') << 'B' << -1 << 'L' << (char)('A'+point.getX()) << (char)('1'+point.getY());
			break;
		}
	}*/
	return os;
}
