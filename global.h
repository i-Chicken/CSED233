#ifndef POINT_H
#define POINT_H

#define MAX_RANGE 9

enum Direction { UP, DOWN, RIGHT, LEFT, DNULL };
enum Team { BLUE, PURPLE, TNULL };
enum UnitType { KING, ATTACK, STUN, BLOCK, TRI, SPLIT, HYPER, UNULL };


class Point{
public:
	Point();
	Point(int, int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	void setPoint(int, int);
	bool operator==(const Point&) const;
	bool operator!=(const Point&) const;
	Point& operator=(const Point&);
private:
	int x;
	int y;
};

#endif
