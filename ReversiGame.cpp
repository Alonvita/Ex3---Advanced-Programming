/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * ReversiGame Class.
 *
 * The ReversiGame class is in charge of starting and ending a game.
 */

#include "ReversiGame.h"

//----------Initializer List----------
/*
 * ReversiGame(Board* gb) Constructor.
 *
 * @param gb Board* -- a reference to the game's board.
 */
ReversiGame::ReversiGame(Board* gb): gameBoard(gb) {
    MANAGER = new TurnsManager();
}

//----------DESTRUCTORS----------
/*
 * ~ReversiGame().
 */
ReversiGame::~ReversiGame() {
    delete manager;
}

//----------PUBLIC FUNCTIONS----------
/*
 * startGame().
 */
void ReversiGame::startGame() {
    //Print the board
    GAME_BOARD.printBoard();
    while((GAME_BOARD.getSpaceLeft())) {
        //Evaluate available moves for player
        MANAGER->evaluateAvailableMovesForThisTurn(this->gameBoard);

        //End turn if player has no available moves
        if(MANAGER->getAvailableMovesNum() == 0) {
            MANAGER->endTurn();
        } else {
            //Nested Functions explanation: moveMade (board) calls:
            //  1). playerMove (manager) -> CellIndex
            //  2). getCurrentPlayerColor (manager) -> Cell
            GAME_BOARD.moveMade(MANAGER->playerMove(GAME_BOARD.getSize()),
                                MANAGER->getCurrentPlayerColor());
            MANAGER->endTurn();

            //Print the board
            GAME_BOARD.printBoard();
        }
    }
    endGame();
}

void ReversiGame::endGame() {
    //Ending announcement
    cout << "The game has ended!" << endl << endl;

    //Print board
    GAME_BOARD.printBoard();

    //Announce Winner
    announceWinner();
}

void ReversiGame::announceWinner() {
    //Local Variables
    int* scores = GAME_BOARD.evaluateFinalScore(); //get scores array
    int winnerScore;
    bool winner;

    if(scores[0] > scores[1]) {
        winnerScore = scores[0];
        winner = 0;
    }else if(scores[0] < scores[1]) {
        winnerScore = scores[1];
        winner = 1;
    }else{
      cout << "!WE HAVE A TIE!";
        return;
    }

    cout << "The winner is: " << generatePlayerName(winner) <<
         " with " << winnerScore << " points. Over " <<
         generatePlayerName(!winner) << " with " <<
         pow(GAME_BOARD.getSize(),2) - winnerScore << " points";

}

/* generatePlayerName(bool b).
 *
 * @param bool b -- a boolean representing true/false so that true is white false is black.
 *
 * @return string representing player's name
 */
string ReversiGame::generatePlayerName(bool b) {
    if(b == 0) { return "WHITE"; }
    return "BLACK";
}