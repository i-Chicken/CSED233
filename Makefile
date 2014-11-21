target: assn2.o cell.o status.o board.o unit.o
	g++ -o assn2.exe assn2.o cell.o status.o board.o unit.o
assn2.o: unit.o cell.o status.o board.o
	g++ -c assn2.cpp
cell.o: cell.cpp cell.h
	g++ -c cell.cpp
status.o: status.cpp status.h
	g++ -c status.cpp
board.o: board.cpp board.h
	g++ -c board.cpp
unit.o: unit.h unit.cpp
	g++ -c unit.cpp
clean:
	rm *.o *.exe
