#ifndef BOARD_H
#define BOARD_H

#include "status.h"
#include <iostream>


void InputSelection(int&);		// check input validity
void InputPosition(int&, int&);	// check input validity

class Board{
public:
	Board(StatusBoard*);
	~Board();
	void startGame();
private: 
	void initGame();
	void showBoard();
	void showBeam();
	void selectUnit(int&, int&);	// input unit from user
	int selectAction(int, int);		// input action from user
    UnitType selectLaser(int&, int&);
	bool commandUnit(int, int, int);	// unit moves or rotate
	int launchLaser(UnitType, Direction, int, int);
	bool beamCurCell(int, int, Direction&);
	int rows, cols;
    int round;
	Team ongoingTeam;
	Cell*** chessboard;
	StatusBoard* statusboard;
};
#endif
