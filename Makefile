target: assn1.o cell.o status.o board.o
	g++ -o assn1.exe assn1.o cell.o status.o board.o
assn1.o: cell.o status.o board.o
	g++ -c assn1.cpp
cell.o: cell.cpp global.h
	g++ -c cell.cpp
status.o: status.cpp global.h
	g++ -c status.cpp
board.o: board.cpp global.h
	g++ -c board.cpp
clean:
	rm *.o assn1.exe
