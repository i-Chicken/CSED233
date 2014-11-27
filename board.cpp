#include "board.h"
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

char InputSelection(string restrain){
	char result;
	char* str = (char*)restrain.c_str();
	do{
		cin >> result;
		cin.clear();
		cin.ignore(256, '\n');
		if (!isInputValid(result, str)){
			cout << "[System] Input Format of command is ";
			for (int i = 0; str[i] != '\0'; i++)
				cout << str[i] << " ";
			cout << endl;
		}
		else        return result;
	} while (1);
	return 0;
}

bool isInputValid(char input, const char* restrain){
	for (int i = 0; restrain[i] != '\0'; i++){
		if (restrain[i] == input) return true;
	}
	return false;
}

Point InputPosition(){
	int r, c;
	do{
		char rt;
		int ct;
		cin >> rt >> ct;
		rt >= 'a' ? r = (int)(rt - 'a') : r = (int)(rt - 'A');		// make small alphabet
		c = ct - 1;
		if (cin.fail() || c < 0 || c >= MAX_RANGE || r >= MAX_RANGE || r < 0){
			cout << "[System] Input Format of position is \"Row Col|\"." << endl;
			cout << "        ex) D 4, e 2, or etc." << endl;
			cin.clear();		// flag 0
			cin.ignore(256, '\n');	//buffer fresh
			continue;
		}
		break;
	} while (1);
	return Point(r, c);
}


Board::Board(StatusBoard* s){
	statusboard = s;
	rows = MAX_RANGE;
	cols = MAX_RANGE;
	chessboard = new Cell**[rows];
	for (int i = 0; i < rows; i++){
		chessboard[i] = new Cell*[cols];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			chessboard[i][j] = new Cell(Point(i, j));	// one Cell for one destrict
		}
	}
	savedata = NULL;
}		//Constructor

char* Board::readFile(ifstream& file){     // format type (turn)Sigma(TEAMi)(UNITi)(stuni)(DIRi)(ROWi)(COLi)
    int turn;
    char team;
    char unit;
    int stun;
	char dir;
    char row;
    char col;
    string result="";
	const char* temp;
	file >> turn;
    if(file.eof() || file.fail() || turn < 1)  return NULL;
    result=result+(char)turn;

	int c =0;
    file >> team;
	while (file.eof() == false){
        if(!isInputValid(team, "BP\0") || file.eof())           return NULL;
        file >> unit;
        if(!isInputValid(unit, "KASBHTP\0") || file.eof())      return NULL;
        file >> stun;
        if(file.eof() || file.fail() || stun < -1)  return NULL;
        file >> dir;
        if(!isInputValid(dir, "UDLR\0") || file.eof())     return NULL;
        file >> row;
        if(!isInputValid(row, "ABCDEFGHI\0") || file.eof())     return NULL;
        file >> col;
        if(!isInputValid(col, "123456789\0"))     return NULL;
        result = result + team + unit + (char)stun + dir + row + col;
		file >> team;
    }
	temp=result.c_str();
    return (char*)result.c_str();   // string -> char*
}

Board::Board(StatusBoard *s, ifstream& file){
	statusboard = s;
	rows = MAX_RANGE;
	cols = MAX_RANGE;
	chessboard = new Cell**[rows];
	for (int i = 0; i < rows; i++){
		chessboard[i] = new Cell*[cols];
	}
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			chessboard[i][j] = new Cell(Point(i, j));	// one Cell for one destrict
		}
	}
    cout << "[System] Loading Game..." << endl;
	savedata = readFile(file);
	if (savedata == NULL){
		cout << "[System] Failure to Load Game!" << endl;
	}
    else{
    }
		// load game from file
}

Board::~Board(){
	for (int i = unit_len - 1; i >= 0; i--)
		delete (units[i]);
	delete units;
	for (int i = rows - 1; i >= 0; i--){
		for (int j = cols - 1; j >= 0; j--){
			delete chessboard[i][j];
		}
		delete[] chessboard[i];
	}
	delete[] chessboard;
}		//Destructor 

void Board::initGame(){
	/* save data index BK-1UA1
	[0] -> stageTurn (int type)
	[1+6*i] -> unitTeam ('B' 'K')
	[1+6*i+1] -> UnitType (char type)
	[1+6*i+2] -> stun (int type)
	[1+6*i+3] -> direction (char type)
	[1+6*i+4] -> row (char type)
	[1+6*i+5] -> col (int type)
	*/

	cout << "[System] Initializing Game.." << endl;
	if (savedata != NULL){
		int len;
		for (len = 0; savedata[len] != 0; len++);
		
		unit_len = (len - 1) / 6;
		units = new Unit*[unit_len];

		for (int i = 0; savedata[1 + 6 * i] != 0; i++){
			char team = savedata[1 + 6 * i];
			char type = savedata[1 + 6 * i + 1];
			int stun = savedata[1 + 6 * i + 2];
			char dir = savedata[1 + 6 * i + 3];
			int row = savedata[1 + 6 * i + 4] - 'A';
			int col = savedata[1 + 6 * i + 5] - '1';

			switch (type){
			case 'K':
				units[i] = new King(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun);	break;
			case 'A':
				switch (dir){
				case 'U':
					units[i] = new AttackLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), UP);	break;
				case 'D':
					units[i] = new AttackLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), DOWN);		break;
				case 'R':
					units[i] = new AttackLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), RIGHT);	break;
				case 'L':
					units[i] = new AttackLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), LEFT);		break;
				}
				break;
			case 'S':
				switch (dir){
				case 'U':
					units[i] = new StunLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), UP);			break;
				case 'D':
					units[i] = new StunLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), DOWN);			break;
				case 'R':
					units[i] = new StunLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), RIGHT);			break;
				case 'L':
					units[i] = new StunLaser(((team == 'P') ? PURPLE : BLUE), Point(row, col), LEFT);			break;
				}
				break;
			case 'B':
				switch (dir){
				case 'U':
					units[i] = new BlockMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, UP);			break;
				case 'D':
					units[i] = new BlockMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, DOWN);			break;
				case 'R':
					units[i] = new BlockMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, RIGHT);			break;
				case 'L':
					units[i] = new BlockMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, LEFT);			break;
				}
				break;
			case 'H':
				switch (dir){
				case 'U':
					units[i] = new HyperMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), UP);			break;
				case 'L':
					units[i] = new HyperMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), LEFT);			break;
				}
				break;
			case 'T':
				switch (dir){
				case 'U':
					units[i] = new TriMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, UP);			break;
				case 'D':
					units[i] = new TriMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, DOWN);			break;
				case 'R':
					units[i] = new TriMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, RIGHT);			break;
				case 'L':
					units[i] = new TriMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, LEFT);			break;
				}
				break;
			case 'P':
				switch (dir){
				case 'U':
					units[i] = new SplitMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, UP);			break;
				case 'D':
					units[i] = new SplitMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, DOWN);			break;
				case 'R':
					units[i] = new SplitMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, RIGHT);			break;
				case 'L':
					units[i] = new SplitMirror(((team == 'P') ? PURPLE : BLUE), Point(row, col), stun, LEFT);			break;
				}
				break;
			}
			chessboard[row][col]->setCell(units[i]);
		}
		round = savedata[0];
		ongoingTeam = ((round % 2 == 1) ? PURPLE : BLUE);
	}
	else{
		units = new Unit*[24];
		unit_len = 24;
		units[0] = new AttackLaser(PURPLE, Point(0, 0), DOWN);
		chessboard[0][0]->setCell(units[0]);
		units[1] = new BlockMirror(PURPLE, Point(0, 4), -1, DOWN);
		chessboard[0][4]->setCell(units[1]);
		units[2] = new King(PURPLE, Point(0, 5), -1);
		chessboard[0][5]->setCell(units[2]);
		units[3] = new BlockMirror(PURPLE, Point(0, 6), -1, DOWN);
		chessboard[0][6]->setCell(units[3]);
		units[4] = new StunLaser(PURPLE, Point(0, 8), DOWN);
		chessboard[0][8]->setCell(units[4]);
		units[5] = new SplitMirror(PURPLE, Point(1, 7), -1, DOWN);
		chessboard[1][7]->setCell(units[5]);
		units[6] = new TriMirror(PURPLE, Point(3, 0), -1, RIGHT);
		chessboard[3][0]->setCell(units[6]);
		units[7] = new TriMirror(PURPLE, Point(3, 2), -1, LEFT);
		chessboard[3][2]->setCell(units[7]);
		units[8] = new HyperMirror(PURPLE, Point(3, 4), UP);
		chessboard[3][4]->setCell(units[8]);
		units[9] = new HyperMirror(PURPLE, Point(3, 5), UP);
		chessboard[3][5]->setCell(units[9]);
		units[10] = new TriMirror(PURPLE, Point(3, 6), -1, DOWN);
		chessboard[3][6]->setCell(units[10]);
		units[11] = new TriMirror(BLUE, Point(3, 8), -1, UP);
		chessboard[3][8]->setCell(units[11]);
		units[12] = new TriMirror(PURPLE, Point(5, 0), -1, DOWN);
		chessboard[5][0]->setCell(units[12]);
		units[13] = new TriMirror(BLUE, Point(5, 2), -1, UP);
		chessboard[5][2]->setCell(units[13]);
		units[14] = new HyperMirror(BLUE, Point(5, 3), UP);
		chessboard[5][3]->setCell(units[14]);
		units[15] = new HyperMirror(BLUE, Point(5, 4), UP);
		chessboard[5][4]->setCell(units[15]);
		units[16] = new TriMirror(PURPLE, Point(5, 6), -1, RIGHT);
		chessboard[5][6]->setCell(units[16]);
		units[17] = new TriMirror(BLUE, Point(5, 8), -1, LEFT);
		chessboard[5][8]->setCell(units[17]);
		units[18] = new TriMirror(BLUE, Point(7, 1), -1, UP);
		chessboard[7][1]->setCell(units[18]);
		units[19] = new StunLaser(BLUE, Point(8, 0), UP);
		chessboard[8][0]->setCell(units[19]);
		units[20] = new BlockMirror(BLUE, Point(8, 2), -1, UP);
		chessboard[8][2]->setCell(units[20]);
		units[21] = new King(BLUE, Point(8, 3), -1);
		chessboard[8][3]->setCell(units[21]);
		units[22] = new TriMirror(BLUE, Point(8, 4), -1, UP);
		chessboard[8][4]->setCell(units[22]);
		units[23] = new AttackLaser(BLUE, Point(8, 8), UP);
		chessboard[8][8]->setCell(units[23]);
		round = 1;
		ongoingTeam = PURPLE;
	}
	hypercell = Point(4, 4);
	cout << "[System] Complete Initializing" << endl;
}

bool Board::gameSave(){
	ofstream file("Savefile", ios::trunc);
	file << round;
	for(int i=0; i<unit_len; i++)
		file << units[i];
	file.close();
	return true;
}

void Board::setCell(){
	Point temp;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			chessboard[i][j]->setCell(NULL);
		}
	}
	for (int i = 0; i < unit_len; i++){
		temp = units[i]->getPos();
		if (temp == hypercell)
			teleUnit(getUnitAt(hypercell));
	}
	for (int i = 0; i < unit_len; i++){
		temp=units[i]->getPos();
		if (temp != Point(-1, -1))
			chessboard[temp.getX()][temp.getY()]->setCell(units[i]);
	}
}

bool Board::teleUnit(Unit* u){
	int r, c;
	srand((unsigned int)time(NULL));
	do{
		r = rand() % 9;
		c = rand() % 9;
		if ((r == 0 && c == 1) || (r == 1 && c == 0))	continue;
		if ((r == 0 && c == 7) || (r == 1 && c == 8))	continue;
		if ((r == 7 && c == 0) || (r == 8 && c == 1))	continue;
		if ((r == 7 && c == 8) || (r == 8 && c == 7))	continue;
		if (u->getPos() == Point(r, c))	continue;
		if (getUnitAt(Point(r, c)) != NULL)	continue;
	} while (0);
	cout << 
	u->setPos(Point(r, c));
	return true;
}
void Board::showBoard(){	//see StatusBoard.printStatus
	setCell();
	statusboard->printStatus(chessboard);
}

void Board::showBeam(){		// see StatusBoard.printBeam
	setCell();
	statusboard->printBeam();
}

Point Board::selectUnit(){
	int r, c;
	char input[256];

	cout << "Player " << (ongoingTeam == PURPLE ? 1 : 2) << "'s turn!" << endl << "Which Unit do you want to control?" << endl;
	cout << "(Input 'x' or \"exit\" if you want to save and quit" << endl;
	do{
		cin.getline(input, 10);
		cout << input << endl;
		if (strcmp(input, "exit") == 0 || input[0] == 'x')	return Point(-1, -1);
		(input[0] >= 'a') ? r = (int)(input[0] - 'a') : r = (int)(input[0] - 'A');		// make small alphabet
		c = input[2] - '1';
		if (cin.fail() || c < 0 || c >= MAX_RANGE || r >= MAX_RANGE || r < 0){
			cout << "[System] Input Format of position is \"Row Col|\"." << endl;
			cout << "        ex) D 4, e 2, or etc." << endl;
			cin.clear();		// flag 0
			cin.ignore(256, '\n');	//buffer fresh
			continue;
		}

		if (chessboard[r][c]->getUnitTeam() != ongoingTeam){		// NOT ongoingTeam's Unit
			cout << "[System] Cannot control object" << endl;
			continue;
		}
		else if (chessboard[r][c]->isUnitStun(round)){
			cout << "[System] Unit is Stunned. choose another unit" << endl;
			continue;
		}
		break;
	} while (1);

	return Point(r, c);
}

int Board::selectAction(Point p){
	Cell* target = chessboard[p.getX()][p.getY()];
	char action;
	switch (target->getUnitType()){
	case KING:
		action = '1';		// King always MOVE
		break;
	case ATTACK:
	case STUN:
		action = '2';		//Laser always ROTATE
		break;
	default:
		cout << "What's your Command of this Unit?" << endl;
		cout << "1. Move		2. Rotate" << endl;
		action = InputSelection("12\0");		// Input constrain to 1(MOVE) or 2(ROTATE)
	}
	return (action - '0');		// returnType 1 == MOVE,  2 == ROTATE
}

Unit* Board::getUnitAt(Point p){
	for (int i = 0; i < unit_len; i++){
		if (units[i]->getPos() == p)	return units[i];
	}
	return NULL;
}

bool Board::commandUnit(Point p, int a){	// boardRow, boardCol, actionType
	Unit* target = getUnitAt(p);
	char action;
	Point moveTo;
	Unit* move;

	switch (a){
	case 1:		// Unit moving;
		cout << "Which posistion do you want it to Move?" << endl;

		moveTo = InputPosition();
		move = getUnitAt(moveTo);
		if (target->moveUnit(moveTo, move))
			return true;
		else
			return false;
		break;
	case 2:		// Unit Rotating;
		switch (chessboard[p.getX()][p.getY()]->getUnitType()){
		case ATTACK:
		case STUN:
		case HYPER:
			cout << "do you want it to Rotate?" << endl;
			cout << "1.OK		2. Cancel" << endl;
			action = InputSelection("10\0");
			if (action == '1'){
				chessboard[p.getX()][p.getY()]->setUnitDir(DNULL);
				cout << "[Log] Player " << ((chessboard[p.getX()][p.getY()]->getUnitTeam() == PURPLE) ? '1' : '2') << " " << (char)('A' + p.getX()) << " " << p.getY() + 1 << " ROTATE" << endl;
			}
			else
				return false;
			break;
		case BLOCK:
		case TRI:
		case SPLIT:
			cout << "Which direction do you want it to Rotate?" << endl;
			cout << "1.LEFT		2.RIGHT" << endl;
			action = InputSelection("10\0");
			action == 1 ? chessboard[p.getX()][p.getY()]->setUnitDir(LEFT) : chessboard[p.getX()][p.getY()]->setUnitDir(RIGHT);
			cout << "[Log] Player " << ((chessboard[p.getX()][p.getY()]->getUnitTeam() == PURPLE) ? '1' : '2') << " " << (char)('A' + p.getX()) << " " << p.getY() + 1 << " ROTATE" << endl;
			break;
		}
		return true;
	}
	return false;
}

int Board::launchLaser(UnitType u, Direction d, Point p){	// 0 - nothing, 1 : PURPLE win, 2 : BLUE win, 3 : DRAW
	int win = 0;
	int r = p.getX();
	int c = p.getY();
	do{
		switch (d){
		case UP:	r--;	break;
		case DOWN:	r++;	break;
		case RIGHT:	c++;	break;
		case LEFT:	c--;	break;
		}	// Direction setting

		if (r >= 9 || r < 0 || c >= 9 || c < 0)	break;	//Out of board
		Direction dtemp = d;
		if (chessboard[r][c]->getUnitType() == UNULL)
			statusboard->setBeam(u, r, c);
		else
			win = win | (1 << chessboard[r][c]->beamCurCell(d, u, round));
		if (d != DNULL && chessboard[r][c]->getUnitType() == SPLIT)
			win = win | launchLaser(u, dtemp, Point(r, c));
	} while (d != DNULL);		// no way to move beam
	return win;		// whether game is over
}

Point Board::selectLaser(){
	char a;
	cout << "Which Laser do you want to launch?" << endl;
	cout << "1. Attack\t2.Stun" << endl;
	a = InputSelection("10\0");
	if (a == '1'){
		if (ongoingTeam == PURPLE)	return Point(0, 0);
		else return Point(8, 8);
	}
	else{
		if (ongoingTeam == PURPLE)	return Point(0, 8);
		else return Point(8, 0);
	}
}

void Board::startGame(){
	int win = 0;
	Point pos;

	initGame();
	while (~(win & (1 << 2)) || ~(win & (1 << 3))){
		showBoard();
		pos = selectUnit();
		if (pos == Point(-1, -1)){
			gameSave();
			break;
		}
		int actionType = selectAction(pos);    //action select
		bool validAction = commandUnit(pos, actionType);	// action perform
		if (validAction == false){
			cout << "[System] Unable command. Try again" << endl;
			continue;
		}
		statusboard->setCell(chessboard);
		Point laser_pos = selectLaser();
		statusboard->resetBeam();
		win = launchLaser(chessboard[laser_pos.getX()][laser_pos.getY()]->getUnitType(), chessboard[laser_pos.getX()][laser_pos.getY()]->getUnitDir(), laser_pos);		//laser launch
		showBeam();
		if ((win & (1 << 2)) && (win & (1 << 3)))
			cout << "Draw ! " << endl;
		else if (win & (1 << 2))
			cout << "Player 1 win! " << endl;
		else if (win & (1 << 3))
			cout << "Player 2 Win! " << endl;
		ongoingTeam == PURPLE ? ongoingTeam = BLUE : ongoingTeam = PURPLE;	//change team
		round++;
	}
}
