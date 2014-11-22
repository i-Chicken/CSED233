#ifndef STUNLASER_H
#define STUNLASER_H


class StunLaser : public Laser{
public:
	StunLaser(Direction, Team, int, int);
	void setRotation();
};


#endif
