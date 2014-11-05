#include<iostream>
#include "global.h"

using namespace std;

extern void InputSelection(int&);
extern void InputPosition(int&, int&);

int main(){
	int input;

	cout << "<< Welcome to Laser Chess!! >>" << endl << endl;
	cout << "What do you want to do?" << endl;
	cout << "1. Start Game		2. Exit Game" <<endl;
	InputSelection(input);
	while(input == 1){
		StatusBoard* s = new StatusBoard();
		Board* b = new Board(s);
		b->startGame();	//game start
		cout << "What do you want to do?" << endl;
		cout << "1. Restart Game		2. Exit Game" << endl;
		InputSelection(input);
		delete s;
		delete b;	// delete Status, Board
	}
	return 0;
}
