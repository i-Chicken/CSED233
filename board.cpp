
#include<iostream>
#include "board.h"

using namespace std;


void InputSelection(int& num){	//using Reference Type
	do{
		cin >> num;
		if(cin.fail() || (num != 1 && num != 2)){
			cin.clear();		//flag 0
			cin.ignore(256, '\n');	// buffer fresh
			cout << "[System] Input Format of command is 1 or 2"<<endl;
			continue;
		}
		break;
	}while(1);
}

void InputPosition(int& r, int& c){	//using Reference Type
	do{
		char rt;
		int ct;
		cin >> rt >> ct;
		rt>='a'?rt-=32:rt=rt;		// make small alphabet

		if(cin.fail() || ct<1 || ct>cols || rt>'Z' || rt<'A'){
			cout << "[System] Input Format of position is \"Row Col|\"."<<endl;
			cout << "        ex) D 4, e 2, or etc." << endl;
			cin.clear();		// flag 0
			cin.ignore(256, '\n');	//buffer fresh
			continue;
		}
		r=rt-'A';		// return value
		c=ct-1;			// return value
		break;
	}while(1);
}


Board::Board(StatusBoard* s){
	statusboard=s;
	rows=MAX_RANGE;
	cols=MAX_RANGE;
	ongoingTeam = PURPLE;

	chessboard = new Cell**[rows];

	for(int i=0; i<rows; i++){
		chessboard[i] = new Cell*[cols];
	}

	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			chessboard[i][j] = new Cell(i, j);	// one Cell for one destrict
		}
	}
}		//Constructor

Board::~Board(){
	for(int i=rows-1; i>=0; i--){
		for(int j=cols-1; j>=0; j--){
			delete chessboard[i][j];
		}
		delete[] chessboard[i];
	}
	delete[] chessboard;
}		//Destructor 

void Board::initGame(){	//setting board
	chessboard[0][0]->setCell(LASER, new Laser(DOWN, PURPLE), false);
	chessboard[0][1]->setCell(UNULL, NULL, false);	// Laser surround
	chessboard[0][1]->setCell(UNULL, NULL, false);	// Laser surround
	chessboard[0][4]->setCell(BLOCK, new BlockMirror(DOWN, PURPLE), false);
	chessboard[0][5]->setCell(KING, new King(PURPLE), false);
	chessboard[0][6]->setCell(BLOCK, new BlockMirror(DOWN, PURPLE), false);
	chessboard[1][7]->setCell(TRI, new TriMirror(DOWN, PURPLE), false);
	chessboard[3][0]->setCell(TRI, new TriMirror(RIGHT, PURPLE), false);
	chessboard[3][2]->setCell(TRI, new TriMirror(LEFT, BLUE), false);
	chessboard[3][4]->setCell(HYPER, new HyperMirror(UP, PURPLE), false);
	chessboard[3][5]->setCell(HYPER, new HyperMirror(UP, PURPLE), false);
	chessboard[3][6]->setCell(TRI, new TriMirror(DOWN, PURPLE), false);
	chessboard[3][8]->setCell(TRI, new TriMirror(UP, BLUE), false);
	chessboard[5][0]->setCell(TRI, new TriMirror(DOWN, PURPLE), false);
	chessboard[5][2]->setCell(TRI, new TriMirror(UP, BLUE), false);
	chessboard[5][3]->setCell(HYPER, new HyperMirror(UP, BLUE), false);
	chessboard[5][4]->setCell(HYPER, new HyperMirror(UP, BLUE), false);
	chessboard[5][6]->setCell(TRI, new TriMirror(RIGHT, PURPLE), false);
	chessboard[5][8]->setCell(TRI, new TriMirror(LEFT, BLUE), false);
	chessboard[7][1]->setCell(TRI, new TriMirror(UP, BLUE), false);
	chessboard[8][2]->setCell(BLOCK, new BlockMirror(UP, BLUE), false);
	chessboard[8][3]->setCell(KING, new King(BLUE), false);
	chessboard[8][4]->setCell(BLOCK, new BlockMirror(UP, BLUE), false);
	chessboard[8][8]->setCell(LASER, new Laser(UP, BLUE), false);
	chessboard[7][8]->setCell(UNULL, NULL, false);	// Laser surround
	chessboard[8][7]->setCell(UNULL, NULL, false);	// Laser surround
}



void Board::showBoard(){	//see StatusBoard.printStatus
	statusboard->printStatus(chessboard);
}

void Board::showBeam(){		// see StatusBoard.printBeam
	statusboard->printBeam();
}

void Board::UnitSelect(int& r, int& c){
	do{
		if(ongoingTeam == PURPLE)
			cout << "Player 1's turn!" << endl << "Which Unit do you want to control?" << endl;
		else
			cout << "Player 2's turn!" << endl << "Which Unit do you want to control?" << endl;

		InputPosition(r, c);
		if(chessboard[r][c]->getUnitTeam() != ongoingTeam){		// NOT ongoingTeam's Unit
			cout << "[System] Cannot control object" << endl;
			continue;
		}
		break;
	}while(1);
}


int Board::ActionSelect(int r, int c){
	Cell* target=chessboard[r][c];
	int action;
	switch(target->getUnitType()){
	case KING:
		action=1;		// King always MOVE
		break;
	case LASER:
		action=2;		//Laser always ROTATE
		break;
	default:
		cout << "What's your Command of this Unit?" << endl;
		cout << "1. Move		2. Rotate" << endl;
		InputSelection(action);		// Input constrain to 1(MOVE) or 2(ROTATE)
	}
	return action;		// returnType 1 == MOVE,  2 == ROTATE
}

bool Board::UnitAction(int r, int c, int a){	// boardRow, boardCol, actionType
	Cell* target=chessboard[r][c];
	int row, col;
	int action;

	switch(target->getUnitType()){
	case KING:	// King just move
		cout << "Which posistion do you want it to Move?" << endl;
		InputPosition(row, col);
		if(row == r && col == c)	return false;	// same cell
		if(chessboard[row][col]->movableTo() && (r-row)*(r-row) <= 1 && (c-col)*(c-col) <= 1){	//accessibilty == true && adjacent cell
			target->moveTo(chessboard[row][col]);
			char rt1=r+'A';		char rt2=row+'A';	// for print [Log]
			cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt1 << " " << c+1 << " => " << rt2 << " " << col+1 << endl;
		}
		else	return false;	// invalid command
		break;
	case LASER:	// Laser just rotate in two way
		cout << "do you want it to Rotate?" << endl;
		cout << "1.OK		2. Cancel" << endl;
		InputSelection(action);
		if(action == 1){		// okay rotate
			target->setUnitDir(DNULL);
			char rt=r+'A';	// for print [Log]
			cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt << " " << c+1 << " ROTATE" << endl;
		}
		else	return false;	// cancel rotation
		break;
	case BLOCK:
		if(a==1){	// Move
			cout << "Which posistion do you want it to Move?" << endl;
			InputPosition(row, col);
			if(row == r && col == c)	return false;
			if(chessboard[row][col]->movableTo() && (r-row)*(r-row) <= 1 && (c-col)*(c-col) <= 1){	//accessibilty == true && adjacent cell
				target->moveTo(chessboard[row][col]);
				char rt1=r+'A';		char rt2=row+'A';	// for print [Log]
				cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt1 << " " << c+1 << " => " << rt2 << " " << col+1 << endl;
			}
			else	return false;	// invalid command
		}
		else{	// Rotate
			cout << "Which direction do you want it to Rotate?" << endl;
			cout << "1.LEFT		2.RIGHT" << endl;
			InputSelection(action);
			action == 1 ? target->setUnitDir(LEFT) : target->setUnitDir(RIGHT);
			char rt=r+'A';	// for print [Log]
			cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt << " " << c+1 << " ROTATE" << endl;
		}
		break;
	case TRI:
		if(a==1){	// Move
			cout << "Which posistion do you want it to Move?" << endl;
			InputPosition(row, col);
			if(row == r && col == c)	return false;
			if(chessboard[row][col]->movableTo() && (r-row)*(r-row) <= 1 && (c-col)*(c-col) <= 1){	//accessibilty == true && adjacent cell
				target->moveTo(chessboard[row][col]);
				char rt1=r+'A';		char rt2=row+'A';	// for print [Log]
				cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt1 << " " << c+1 << " => " << rt2 << " " << col+1 << endl;
			}
			else	return false;	// invalid command
		}
		else{		// Rotate
			cout << "Which direction do you want it to Rotate?" << endl;
			cout << "1.LEFT		2.RIGHT" << endl;
			InputSelection(action);
			action == 1 ? target->setUnitDir(LEFT) : target->setUnitDir(RIGHT);
			char rt=r+'A';
			cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt << " " << c+1 << " ROTATE" << endl;
		}
		break;
	case HYPER:
		if(a==1){	// Move
			cout << "Which posistion do you want it to Move?" << endl;
			InputPosition(row, col);
			if(row == r && col == c)	return false;
			if((r-row)*(r-row) <= 1 && (c-col)*(c-col) <= 1){	// adjacent cell
				if(chessboard[row][col]->movableTo()){			// Not Laser adjacent & empty cell
					target->moveTo(chessboard[row][col]);
					char rt1=r+'A';		char rt2=row+'A';	// for print [Log]
					cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt1 << " " << c+1 << " => " << rt2 << " " << col+1 << endl;
				}
				else if(chessboard[row][col]->getUnitType() == LASER || chessboard[row][col]->getUnitType() == UNULL)
				   return false;	// Laser or Laser adjacent
				else{	// swap two unit
				   target->swapWith(chessboard[row][col]);
				   char rt1=r+'A';		char rt2=row+'A';	// for print [Log]
				   cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt1 << " " << c+1 << " => " << rt2 << " " << col+1 << endl;
				}
			}
		}
		else{	// Rotate
			cout << "do you want it to Rotate?" << endl;
			cout << "1.OK		2. Cancel" << endl;
			InputSelection(action);
			if(action == 1){
				target->setUnitDir(DNULL);
				char rt=r+'A';	// for print [Log]
				cout << "[Log] Player " << ((target->getUnitTeam() == PURPLE) ? '1':'2') << " " << rt << " " << c+1 << " ROTATE" << endl;
			}
			else	return false;	// cancel rotation
		}
		break;
	}

	return true;
}



bool Board::launchLaser(){
	int r, c;
	Direction d;
	ongoingTeam==PURPLE ? r=c=0:r=c=8;
	d=chessboard[r][c]->getUnitDir();
	bool win=false;

	statusboard->resetBeam();	// reset beam[][]

	do{
		switch(d){
		case UP:	r--;	break;
		case DOWN:	r++;	break;
		case RIGHT:	c++;	break;
		case LEFT:	c--;	break;
		}	// Direction setting

		if(r>=9 || r<0 || c>=9 || c<0)	break;	//Out of board
		win = beamCurCell(r, c, d);
	}while(d!=DNULL);		// no way to move beam
	
	statusboard->setCell(chessboard);	// setting synchronous
	statusboard->printBeam();
	if(win){		// game over
		if(chessboard[r][c]->getUnitTeam() == PURPLE)
			cout << "Player 2's Victory!" << endl;
		else
			cout << "Player 1's Victory!" << endl;
	}
	return win;		// whether game is over
}


bool Board::beamCurCell(int r, int c, Direction& d){
	Cell* target=chessboard[r][c];
	Direction temp=d;
	char tempc=r+'A';	// for printing [Log]

	switch(target->getUnitType()){
	case KING:
		d=DNULL;
		cout << "[Laser] King of Player " << (target->getUnitTeam() == PURPLE ? 1:2) << "is defeated" << endl;
		return true;	// game over

	case LASER:
		d=DNULL;
		return false;	// laser nothing happen
	case BLOCK:
		if(target->getUnitDir() == RIGHT && d == LEFT)	d=DNULL;
		else if(target->getUnitDir() == UP && d == DOWN)	d=DNULL;
		else if(target->getUnitDir() == LEFT && d == RIGHT)	d=DNULL;
		else if(target->getUnitDir() == DOWN && d == UP)	d=DNULL;	// beam blocking
		else{
			target->removeUnit();
			cout << "[Laser] BlockMirror " << tempc << " " << c+1 << " is Destroyed" << endl;
			d=DNULL;
		}	//block destroy
		return false;
	case TRI:
		switch(d){
		case LEFT:
			if(target->getUnitDir() == DOWN)	d=DOWN;
			else if(target->getUnitDir() == RIGHT)	d=UP;
			break;
		case DOWN:
			if(target->getUnitDir() == RIGHT)	d=RIGHT;
			else if(target->getUnitDir() == UP)		d=LEFT;
			break;
		case RIGHT:
			if(target->getUnitDir() == UP)		d=UP;
			else if(target->getUnitDir() == LEFT)		d=DOWN;
			break;
		case UP:
			if(target->getUnitDir() == LEFT)		d=LEFT;
			else if(target->getUnitDir() == DOWN)		d=RIGHT;
			break;
		}	// beam reflection
		if(temp == d){	// temp == original direction
			target->removeUnit();
			cout << "[Laser] TriMirror " << tempc << " " << c+1 << " is Destroyed" << endl;
			d=DNULL;
		}	//Tri destroy
		return false;
	case HYPER:
		switch(d){
		case LEFT:
			target->getUnitDir() == UP ? d=DOWN : d=UP;
			break;
		case DOWN:
			target->getUnitDir() == UP ? d=LEFT : d=RIGHT;
			break;
		case RIGHT:
			target->getUnitDir() == UP ? d=UP : d=DOWN;
			break;
		case UP:
			target->getUnitDir() == UP ? d=RIGHT : d=LEFT;
			break;
		}	// beam reflection
		return false;
	case UNULL:	//empty cell
		statusboard->setBeam(r, c);
		return false;
	}
	return false;
}



void Board::startGame(){
	bool win=false;
	int row, col;

	cout << "[System] Initializing Game.." << endl;
	initGame();
	cout << "[System] Complete Initializing." << endl;
	while(!win){
		showBoard();

		UnitSelect(row, col);
		int actionType = ActionSelect(row, col);		//action select
		bool validAction = UnitAction(row, col, actionType);	// action perform
		if(validAction == false){
			cout << "[System] Unable command. Try again" << endl;
			continue;
		}
		win=launchLaser();		//laser launch

		ongoingTeam == PURPLE ? ongoingTeam=BLUE : ongoingTeam=PURPLE;	//change team
	}

}
