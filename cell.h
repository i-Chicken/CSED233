#ifndef CELL_H
#define CELL_H

class Cell{
public:
	Cell(int, int);
	~Cell();
	bool movableTo();
	void removeUnit();
	void setCell(UnitType, Unit*, bool);
	void setUnitDir(Direction);
	bool movableTo(UnitType, int, int);
	void moveTo(Cell*);
	void swapWith(Cell*);
	Team getUnitTeam();
	Direction getUnitDir();
	UnitType getUnitType();

private:
	int row, col;
	Unit* unit;
	bool accessible;
}

#endif
