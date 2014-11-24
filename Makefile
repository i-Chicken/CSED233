target: assn3.o cell.o status.o board.o unit.o king.o laser.o attacklaser.o stunlaser.o mirror.o blockmirror.o trimirror.o splitmirror.o hypermirror.o global.o
	g++ -o assn3.exe assn3.o cell.o status.o board.o unit.o king.o laser.o attacklaser.o stunlaser.o mirror.o blockmirror.o trimirror.o splitmirror.o hypermirror.o point.o
assn3.o: unit.o cell.o status.o board.o
	g++ -c assn3.cpp
cell.o: cell.cpp cell.h
	g++ -c cell.cpp
status.o: status.cpp status.h
	g++ -c status.cpp
board.o: board.cpp board.h
	g++ -c board.cpp
hypermirror.o: hypermirror.h hypermirror.cpp mirror.o
	g++ -c hypermirror.cpp
splitmirror.o: splitmirror.h splitmirror.cpp mirror.o
	g++ -c splitmirror.cpp
trimirror.o: trimirror.h trimirror.cpp mirror.o
	g++ -c trimirror.cpp
blockmirror.o: blockmirror.h blockmirror.cpp mirror.o
	g++ -c blockmirror.cpp
mirror.o: mirror.h mirror.cpp unit.o
	g++ -c mirror.cpp
stunlaser.o: stunlaser.h stunlaser.cpp laser.o
	g++ -c stunlaser.cpp
attacklaser.o: attacklaser.h attacklaser.cpp laser.o
	g++ -c attacklaser.cpp
laser.o: laser.h laser.cpp unit.o
	g++ -c laser.cpp
king.o: king.h king.cpp unit.o
	g++ -c king.cpp
unit.o: unit.h unit.cpp global.o
	g++ -c unit.cpp
point.o: global.h global.cpp
	g++ -c global.cpp
clean:
	rm *.o *.exe
