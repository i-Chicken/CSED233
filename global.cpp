#include "global.h"

Point::Point(){};
Point::Point(int x, int y){
	this->x = x;
	this->y = y;
}

int Point::getX(){ return this->x; }
int Point::getY(){ return this->y; }

void Point::setX(int x){
	this->x = x;
}

void Point::setY(int y){
	this->y = y;
}

void Point::setPoint(int x, int y){
	this->x = x;
	this->y = y;
}

bool Point::operator==(const Point& p) const{
	if (p.x == x && p.y == y)	return true;
	else return false;
}

bool Point::operator!=(const Point& p) const{
	if (p.x != x || p.y != y)	return true;
	return false;
}

Point& Point::operator=(const Point& p){
	x = p.x;
	y = p.y;
	return *this;
}