#ifndef UNIT_H
#define UNIT_H

enum Direction { UP, DOWN, RIGHT, LEFT, DNULL };
enum Team { BLUE, PURPLE, TNULL };
enum UnitType { KING, ATTACK, STUN, BLOCK, TRI, SPLIT, HYPER, UNULL };

class Unit{
public:
	Unit(UnitType, Team, int, int);	// unittype, team, row, col
	Team getTeam();
	UnitType getUnitType();
	void moveUnit(int, int);
	void stunUnit(int);     // Unit stunned by laser
	bool isStun(int);       // verify unit is stun
protected:
	Team team;
	UnitType unittype;
	int row;
	int col;
	int stun;
};

#endif
