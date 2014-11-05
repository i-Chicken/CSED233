#ifndef UNIT_H
#define UNIT_H

enum Direction { UP, DOWN, RIGHT, LEFT, DNULL };
enum Team { BLUE, PURPLE, TNULL };
enum UnitType { KING, ATTACK, STUN, BLOCK, TRI, SPLIT, HYPER, UNULL };



class Unit{
public:
	Unit(UnitType, Team, int, int);
	Team getTeam();
	UnitType getUnitType();
	void moveUnit(int, int);
	void stunUnit(int);
	bool isStun(int);
protected:
	Team team;
	UnitType unittype;
	int row;
	int col;
	int stun;
};

class King : public Unit{
public:
	King(Team);
};

class Laser: public Unit{
public:
	Laser(Direction, UnitType, Team, int, int);
	Direction getDirection();
protected:
	Direction direction;
};

class AttackLaser : public Laser{
public:
	AttackLaser(Direction, Team, int, int);
	void setRotation();
};

class StunLaser : public Laser{
public:
	StunLaser(Direction, Team, int, int);
	void setRotation();
};

class Mirror : public Unit{
public:
	Mirror(Direction, UnitType, Team, int, int);
	Direction getDirection();
protected:
	Direction direction;
};

class BlockMirror: public Mirror{
public:
	BlockMirror(Direction, Team, int, int);
	void setRotation(Direction d);
};

class TriMirror{
public:
	TriMirror(Direction, Team, int, int);
	void setRotation(Direction d);
};

class SplitMirror : public Mirror{
public:
	SplitMirror(Direction, Team, int, int);
	void setRotation(Direction d);
};

class HyperMirror{
public:
	HyperMirror(Direction, Team, int, int);	//UP, LEFT
	void setRotation(Direction d);
};

#endif
