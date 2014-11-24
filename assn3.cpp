#include <iostream>
#include "unit.h"
#include "cell.h"
#include "status.h"
#include "board.h"
#include <fstream>
#include <string>

using namespace std;

extern char InputSelection(string);
extern bool isInputValid(char , const char*);	// Input validity function

int main(){
	char input;
    StatusBoard* s;
    Board* b;

	cout << "<< Welcome to Laser Chess!! >>" << endl << endl;
	do{
	    cout << "What do you want to do?" << endl;
        ifstream savefile("Savefile");		// same directory with .exe
        if(savefile.is_open() == true){
            cout << "1. New Game\t\t2. Load Game\t\t0. Exit Game" << endl;
            input=InputSelection("120\0");
        }
        else{
	        cout << "1. Start Game\t\t0. Exit Game" <<endl;
	        input = InputSelection("10\0");
        }
        if(input == '1'){
		    s = new StatusBoard();
		    b = new Board(s);
        }   ////////////// New Game or No file exist
		else if(input == '2'){
			s = new StatusBoard();
			b = new Board(s, savefile);
			savefile.close();
		}
        else if(input == '0') break;
		b->startGame();	//game start
		cout << "What do you want to do?" << endl;
		cout << "1. Restart Game		0. Exit Game" << endl;
		input=InputSelection("10\0");
		delete b;
		delete s;
		// delete Status, Board
	}while(input != '0');
	return 0;
}