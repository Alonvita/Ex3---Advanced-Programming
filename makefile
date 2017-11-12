#311233431
#Alon Vita

a.out: Board.o GameUtilities.o Player.o ReversiGame.o TurnsManager.o main.o
	g++ Board.o GameUtilities.o Player.o ReversiGame.o TurnsManager.o main.o

Board.o: Board.cpp Board.h Cell.h
	g++ -c Board.cpp

GameUtilities.o: GameUtilities.cpp GameUtilities.h Cell.h
	g++ -c GameUtilities.cpp

Player.o: Player.cpp Player.h Cell.h
	g++ -c Player.cpp

ReversiGame.o: ReversiGame.cpp ReversiGame.h Board.h TurnsManager.h  
	g++ -c ReversiGame.cpp

TurnsManager.o: TurnsManager.cpp TurnsManager.h Board.h Cell.h GameUtilities.h Player.h 
	g++ -c TurnsManager.cpp

main.o: main.cpp Board.h ReversiGame.h
	g++ -c main.cpp
