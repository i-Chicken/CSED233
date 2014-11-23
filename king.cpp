#include "king.h"


King::King(Team t, int r, int c): Unit(KING, t, r, c){}; 
bool King::moveUnit(int r, int c){
	row=r;
	col=c;
	return true;
}

bool King::rotateUnit(Direction d){
	return false;
}

Direction King::getDireciton(){
	return DNULL;
}

int beamUnit(Direction& d, UnitType u, int round){
	d=DNULL;
	if(u == ATTACK){
		cout << "[System] King of Player " << (team == PURPLE ? 1:2) << "is defeated" << endl;
		return (team == PURPLE ? 1:2);
	}
	else{
		cout << "[System] Player " << (team == PURPLE ? 1:2) << "'s Unit at (" << (char)('A'+row) << " " << col+1 << ") is in stun." << endl;
		stunUnit(round);
		return 0;
	}
}
