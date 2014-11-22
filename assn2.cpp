#include <iostream>
#include "unit.h"
#include "cell.h"
#include "status.h"
#include "board.h"
#include <fstream>
#include <string>

using namespace std;

extern void InputPosition(int&, int&);

char InputSelection(char*);
bool gameSave(fstream, Board*);
bool isValidFile(fstream);
bool isInputValid(char input, const char* restrain);
char* readFile(ifstream&);

int main(){
	char input;
    StatusBoard* s;
    Board* b;

	cout << "<< Welcome to Laser Chess!! >>" << endl << endl;
	do{
	    cout << "What do you want to do?" << endl;
        ifstream savefile("Savefile");
        if(savefile != NULL){
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
            cout << "[System] Loading Game..." << endl;
            char* savedata=readFile(savefile);
            cout << savedata << endl;
            if(savedata==NULL){
                cout << "[System] Failure to Load Game!" << endl;
                s = new StatusBoard();
                b = new Board(s);
            }
            else{
                s = new StatusBoard();
                b = new Board(s, savedata);
            }
            savefile.close();
        }   ////////////////// Load Game from file
        else if(input == 0) break;
		b->startGame();	//game start
		cout << "What do you want to do?" << endl;
		cout << "1. Restart Game		2. Exit Game" << endl;
		InputSelection("10\0");
		delete s;
		delete b;	// delete Status, Board
	}while(input != 0);
	return 0;
}

char* readFile(ifstream& file){
    char team;
    char unit;
    char row;
    char col;
    string result="";

    file >> team;
    while(!file.eof()){
        if(!isInputValid(team, "12\0") || file.eof())           return NULL;
        file >> unit;
        if(!isInputValid(unit, "kasbhtp\0") || file.eof())      return NULL;
        file >> row;
        if(!isInputValid(row, "012345678\0") || file.eof())     return NULL;
        file >> col;
        if(!isInputValid(col, "012345678\0"))     return NULL;
        result=result + team + unit + row + col;
        file >> team;
    }
    return (char*)result.c_str();
}

bool isInputValid(char input, const char* restrain){
    for(int i=0; restrain[i] != '\0'; i++){
        if(restrain[i] == input) return true;
    }
    return false;
}

char InputSelection(char* str){
    char result;
    do{
        cin >> result;
        cin.clear();
        cin.ignore(256, '\n');
        if(!isInputValid(result, str)){
            cout << "[System] Input Format of command is ";
            for(int i=0; str[i] != '\0'; i++)
                cout << str[i] << " ";
            cout << endl;
        }
        else        return result;
    }while(1);
    return 0;
}
