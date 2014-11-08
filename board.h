#ifndef BOARD_H
#define BOARD_H

#include "status.h"
#include <iostream>


void InputSelection(int&);		// check input validity
void InputPosition(int&, int&);	// check input validity

class Board{
public:
	Board(StatusBoard*, int, int);
	~Board();
	void startGame();
private: 
	void initGame();
	void showBoard();
	void showBeam();
	void selectUnit(int&, int&);	// input unit from user
	int selectAction(int, int);		// input action from user
	bool commandUnit(int, int, int);	// unit moves or rotate
	bool launchLaser();
	bool beamCurCell(int, int, Direction&);
	int rows, cols;
	Team ongoingTeam;
	Cell*** chessboard;
	StatusBoard* statusboard;
};
#endif
