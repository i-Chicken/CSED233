#ifndef STATUS_H
#define STATUS_H

#include "cell.h"

#define MAX_RANGE 9

class StatusBoard{
public:
	StatusBoard();
	~StatusBoard();
	void resetBeam();
	void setCell(Cell***);
	void printStatus(Cell***);
	void setBeam(UnitType, int, int);
	void printBeam();
private:
	char** status;
	int rows, cols;
	int boardRows;
	int boardCols;
	int** beam;
};

#endif
