#ifndef UNIT_H
#define UNIT_H

enum Direction { UP, DOWN, RIGHT, LEFT, DNULL };
enum Team { BLUE, PURPLE, TNULL };
enum UnitType { KING, ATTACK, STUN, BLOCK, TRI, SPLIT, HYPER, UNULL };

class Unit{
public:
	Unit(Team, int, int, int);	// team, stun, row, col
	Team getTeam();
	virtual int moveUnit(int, int)=0;	// 0 - unable move, 1 - possible, 2- stunning
	virtual bool rotateUnit(Direction)=0;	// 0 - unable move, 1 - possible
	virtual int beamUnit(Direction, UnitType, int)=0;	// 1 - PURPLE king down, 2 - BLUE king down
	bool isStun(int);
protected:
	Team team;
	int row;
	int col;
	int stun;
	void stunUnit(int);     // Unit stunned by laser
};

#endif
