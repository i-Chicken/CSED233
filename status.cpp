#include<iostream>
#include "status.h"

using namespace std;

StatusBoard::StatusBoard(){
	boardRows=MAX_RANGE;	boardCols=MAX_RANGE; 
	rows=MAX_RANGE*2;	cols=MAX_RANGE*2;
	status = new char*[rows];
	for(int i=0; i<rows; i++){
		status[i] = new char[cols];
		for(int j=0; j<cols; j++)	status[i][j]=0;	// memory for Unit icon
	}

	beam = new int*[boardRows];
	for(int i=0; i<boardRows; i++){
		beam[i] = new int[boardCols];
		for(int j=0; j<boardCols; j++)	beam[i][j]=0;	// memory for beam
	}
}
//////////////////////////////// Constructor
StatusBoard::~StatusBoard(){
	for(int i=rows-1; i>=0; i--)
		delete status[i];
	for(int i=boardRows-1; i>=0; i--)
		delete beam[i];
	delete[] status;
	delete[] beam;
}
///////////////////////////////// Deconstructor

void StatusBoard::setCell(Cell*** chessboard){
	for(int i=0; i<boardRows; i++){
		for(int j=0; j<boardCols; j++){
			switch (chessboard[i][j]->getUnitType()){
			case KING:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					status[i*2][j*2]		= 'K';
					status[i*2][j*2+1]	= 'K';
					status[i*2+1][j*2]	= 'K';
					status[i*2+1][j*2+1]	= 'K';
				}
				else{
					status[i*2][j*2]		= 'k';
					status[i*2][j*2+1]	= 'k';
					status[i*2+1][j*2]	= 'k';
					status[i*2+1][j*2+1]	= 'k';
				}
				break;	// for KING

			case BLOCK:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 'B';
						status[i*2][j*2+1]	= 'B';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= '-';
						break;
					case UP:
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 'B';
						status[i*2+1][j*2+1]	= 'B';
						break;
					case LEFT:
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= 'B';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= 'B';
						break;
					case RIGHT:
						status[i*2][j*2]		= 'B';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'B';
						status[i*2+1][j*2+1]	= '|';
						break;
					}
				}
				else{
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 'b';
						status[i*2][j*2+1]	= 'b';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= '-';
						break;
					case UP:
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 'b';
						status[i*2+1][j*2+1]	= 'b';
						break;
					case LEFT:
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= 'b';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= 'b';
						break;
					case RIGHT:
						status[i*2][j*2]		= 'b';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'b';
						status[i*2+1][j*2+1]	= '|';
						break;
					}
				}
				break;	// for BLOCK

			case TRI:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 'T';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= '\0';
						break;
					case RIGHT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= '\0';
						status[i*2+1][j*2]	= 'T';
						status[i*2+1][j*2+1]	= '\\';
						break;
					case UP:
						status[i*2][j*2]		= '\0';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 'T';
						break;
					case LEFT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 'T';
						status[i*2+1][j*2]	= '\0';
						status[i*2+1][j*2+1]	= '\\';
						break;
					}
				}
				else{
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 't';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= '\0';
						break;
					case RIGHT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= '\0';
						status[i*2+1][j*2]	= 't';
						status[i*2+1][j*2+1]	= '\\';
						break;
					case UP:
						status[i*2][j*2]		= '\0';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 't';
						break;
					case LEFT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 't';
						status[i*2+1][j*2]	= '\0';
						status[i*2+1][j*2+1]	= '\\';
						break;
					}
				}
				break;	// for TriMirror


			case SPLIT:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 'S';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= '\0';
						break;
					case RIGHT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= '\0';
						status[i*2+1][j*2]	= 'S';
						status[i*2+1][j*2+1]	= '\\';
						break;
					case UP:
						status[i*2][j*2]		= '\0';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 'S';
						break;
					case LEFT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 'S';
						status[i*2+1][j*2]	= '\0';
						status[i*2+1][j*2+1]	= '\\';
						break;
					}
				}
				else{
					switch(chessboard[i][j]->getUnitDir()){
					case DOWN:
						status[i*2][j*2]		= 's';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= '\0';
						break;
					case RIGHT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= '\0';
						status[i*2+1][j*2]	= 's';
						status[i*2+1][j*2+1]	= '\\';
						break;
					case UP:
						status[i*2][j*2]		= '\0';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 's';
						break;
					case LEFT:
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 's';
						status[i*2+1][j*2]	= '\0';
						status[i*2+1][j*2+1]	= '\\';
						break;
					}
				}
				break;

			case HYPER:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= 'H';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 'H';
					}
					else{
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 'H';
						status[i*2+1][j*2]	= 'H';
						status[i*2+1][j*2+1]	= '\\';
					}
				}
				else{
					if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= 'h';
						status[i*2][j*2+1]	= '/';
						status[i*2+1][j*2]	= '/';
						status[i*2+1][j*2+1]	= 'h';
					}
					else{
						status[i*2][j*2]		= '\\';
						status[i*2][j*2+1]	= 'h';
						status[i*2+1][j*2]	= 'h';
						status[i*2+1][j*2+1]	= '\\';
					}
				}
				break;	// for HyperMirror

			case ATTACK:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					if(chessboard[i][j]->getUnitDir() == DOWN){
						status[i*2][j*2]		= 'R';
						status[i*2][j*2+1]	= 'R';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= '|';
					}
					else if(chessboard[i][j]->getUnitDir() == RIGHT){
						status[i*2][j*2]		= 'R';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 'R';
						status[i*2+1][j*2+1]	= '-';
					}
					else if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'R';
						status[i*2+1][j*2+1]	= 'R';
					}
					else{
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= 'R';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= 'R';
					}
				}
				else{
					if(chessboard[i][j]->getUnitDir() == DOWN){
						status[i*2][j*2]		= 'r';
						status[i*2][j*2+1]	= 'r';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= '|';
					}
					else if(chessboard[i][j]->getUnitDir() == RIGHT){
						status[i*2][j*2]		= 'r';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 'r';
						status[i*2+1][j*2+1]	= '-';
					}
					else if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'r';
						status[i*2+1][j*2+1]	= 'r';
					}
					else{
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= 'r';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= 'r';
					}
				}
				break;		// for Laser

			case STUN:
				if(chessboard[i][j]->getUnitTeam() == PURPLE){
					if(chessboard[i][j]->getUnitDir() == DOWN){
						status[i*2][j*2]		= 'S';
						status[i*2][j*2+1]	= 'R';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= '|';
					}
					else if(chessboard[i][j]->getUnitDir() == RIGHT){
						status[i*2][j*2]		= 'R';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 'S';
						status[i*2+1][j*2+1]	= '-';
					}
					else if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'R';
						status[i*2+1][j*2+1]	= 'S';
					}
					else{
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= 'S';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= 'R';
					}
				}
				else{
					if(chessboard[i][j]->getUnitDir() == DOWN){
						status[i*2][j*2]		= 's';
						status[i*2][j*2+1]	= 'r';
						status[i*2+1][j*2]	= '|';
						status[i*2+1][j*2+1]	= '|';
					}
					else if(chessboard[i][j]->getUnitDir() == RIGHT){
						status[i*2][j*2]		= 'r';
						status[i*2][j*2+1]	= '-';
						status[i*2+1][j*2]	= 's';
						status[i*2+1][j*2+1]	= '-';
					}
					else if(chessboard[i][j]->getUnitDir() == UP){
						status[i*2][j*2]		= '|';
						status[i*2][j*2+1]	= '|';
						status[i*2+1][j*2]	= 'r';
						status[i*2+1][j*2+1]	= 's';
					}
					else{
						status[i*2][j*2]		= '-';
						status[i*2][j*2+1]	= 's';
						status[i*2+1][j*2]	= '-';
						status[i*2+1][j*2+1]	= 'r';
					}
				}
				break;		// for StunLaser
			default:
				status[i*2][j*2]		= '\0';
				status[i*2][j*2+1]		= '\0';
				status[i*2+1][j*2]		= '\0';
				status[i*2+1][j*2+1]	= '\0';
				break;		// for Empty Cell
			}
		}
	}
};


void StatusBoard::printStatus(Cell*** chessboard){
	setCell(chessboard);
	for(int i=0; i< (boardCols+1)*3; i++)
		cout << '=';
	cout << endl << "   ";		// Top of Top

	for(int i=0; i < boardCols; i++)
		cout << " " << i+1 << " ";	// Col Index
	cout << endl;

	for(int i=0; i < boardRows; i++){
		for(int j=-1; j < boardCols; j++){
			char r='A'+i;
			if(j == -1)		// Row Index
				cout << " " << r << " ";
			else
				cout << status[i*2][j*2] << status[i*2][j*2+1] << " ";
		}
		cout << endl;
		for(int j=-1; j < boardCols; j++){
			if(j == -1)		// index empty line
				cout << "   ";
			else
				cout << status[i*2+1][j*2] << status[i*2+1][j*2+1] << " ";
		}
		cout << endl;
	}

	for(int i=0; i< (boardCols+1)*3; i++)
		cout << '=';			// bottom 
	cout << endl;
}

void StatusBoard::resetBeam(){	// make all Zeros
	for(int i=0; i<boardRows; i++){
		for(int j=0; j<boardCols; j++){
			beam[i][j]=false;
		}
	}
}

void StatusBoard::setBeam(int r, int c){	// 1 - for Attack 2 - for Stun
	beam[r][c]=true;
}

void StatusBoard::printBeam(){
	for(int i=0; i< (boardCols+1)*3; i++)
		cout << '=';
	cout << endl << "   ";

	for(int i=0; i < boardCols; i++)
		cout << " " << i+1 << " ";		// col index
	cout << endl;

	for(int i=0; i < boardRows; i++){
		char r='A'+i;
		for(int j=-1; j < boardCols; j++){
			if(j == -1)			// row index
				cout << " " << r << " ";
			else{
				if(beam[i][j] == 1)		// beam exist
					cout << "## ";
				else if(beam[i][j] == 2)
					cout << "XX ";
				else
					cout << status[i*2][j*2] << status[i*2][j*2+1] << " ";
			}
		}
		cout << endl;
		for(int j=-1; j < boardCols; j++){
			if(j == -1)			// index empty line
				cout << "   ";
			else{
				if(beam[i][j] == 1)		// beam exist
					cout << "## ";
				else if(beam[i][j] == 2)
					cout << "XX ";
				else
					cout << status[i*2+1][j*2] << status[i*2+1][j*2+1] << " ";
			}
		}
		cout << endl;
	}

	for(int i=0; i< (boardCols+1)*3; i++)
		cout << '=';
	cout << endl;
}
