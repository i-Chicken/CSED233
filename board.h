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
	void initGame(); 
	void showBoard();
	void showBeam();
	void UnitSelect(int&, int&);	// input unit from user
	int ActionSelect(int, int);		// input action from user
	bool UnitAction(int, int, int);	// unit moves or rotate
	bool launchLaser();
	bool beamCurCell(int, int, Direction&);
	void startGame();
	bool MoveUnitTo(Cell*, int, int);
private: 
	int rows, cols;
	Team ongoingTeam;
	Cell*** chessboard;
	StatusBoard* statusboard;
};
#endif
