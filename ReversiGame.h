/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * ReversiGame Class.
 *
 * The ReversiGame class is in charge of starting and ending a game.
 */

#ifndef REVERSIGAME_H_
#define REVERSIGAME_H_


//----------INCLUDING----------
#include <string>
#include "Board.h"
#include "TurnsManager.h"

//----------DEFINITIONS----------
#define GAME_BOARD (*(this->gameBoard))
#define MANAGER this->manager

class ReversiGame {
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializers
    ReversiGame(Board* gb);
    //Destructor
    ~ReversiGame();
    //Utilities
    void 				startGame();

private:
    //----------VARIABLES----------
    Board* 				gameBoard;
    TurnsManager* 		manager;

    //----------PRIVATE FUNCTIONS----------
    void                endGame();
    void                announceWinner();
    string              generatePlayerName(bool b);
};


#endif /* REVERSIGAME_H_ */