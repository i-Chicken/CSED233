
#ifndef GLOBAL_H
#define GLOBAL_H


class Cell{
public:
	Cell(int, int);
	~Cell();
	bool movableTo();
	void removeUnit();
	void setCell(UnitType, void*, bool);
	void setUnitDir(Direction);//
	void moveTo(Cell*);//
	void swapWith(Cell*);
	Team getUnitTeam();
	Direction getUnitDir();
	UnitType getUnitType();
private:
	int row, col;
	UnitType unittype;
	bool accessible;
	King* king;
	Laser* laser;
	BlockMirror* block;
	TriMirror* tri;
	HyperMirror* hyper;
};


class StatusBoard{
public:
	StatusBoard(int, int);
	~StatusBoard();
	void resetBeam();
	void setCell(Cell***);
	void printStatus(Cell***);
	void setBeam(int, int);
	void printBeam();
private:
	char** status;
	int rows, cols;
	int boardRows;
	int boardCols;
	bool** beam;
};



class Board{
public:
	Board(StatusBoard*, int, int);
	~Board();
	void initGame(); 
	void showBoard();
	void showBeam();
	void InputSelection(int&);		// check input validity
	void InputPosition(int&, int&);	// check input validity
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
