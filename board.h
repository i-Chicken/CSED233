#ifndef BOARD_H
#define BOARD_H

#include "status.h"
#include <iostream>
#include <string>

char InputSelection(string);		// check input validity
Point InputPosition();	// check input validity
bool isInputValid(char , const char*);

class Board{
public:
	Board(StatusBoard*);
    Board(StatusBoard*, char*);
	~Board();
	void startGame();
private: 
	void initGame();
    void initGame(char*);
	void showBoard();
	void showBeam();
	Point selectUnit();	// input unit from user
	int selectAction(Point);		// input action from user
    Point selectLaser();
	Unit* getUnitAt(Point);
	bool commandUnit(Point, int);	// unit moves or rotate
	int launchLaser(UnitType, Direction, Point);
	int rows, cols;
    int round;
	Team ongoingTeam;
	Cell*** chessboard;
	StatusBoard* statusboard;
	Unit** units;
	int unit_len;
	char* savedata;
};
#endif
