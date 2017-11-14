/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * AI Class.
 *
 * An AI is a computer that will serve as a second player. It will
 *  evaluate it's best moves to make and send them as a string to
 *  the TurnsManager.
 *
 */

//----------INCLUDING---------
#include "AI.h"
#include "MovesEvaluator.h"

//----------INITIALIZER-LIST----------
/*
 * AI(Cell c, Board* gb) Constructor.
 *
 * @param gb Board -- the game's board
 */
AI::AI(Board* gameBoard): Player(WHITE, gameBoard) {}

//----------PUBLIC FUNCTIONS----------
/*
 * makeMove().
 *
 * @return string -- a raw string of player's move
 */
CellIndex AI::makeAMove(vector<CellIndex> aMoves) const {
    //Local Variables
    vector<CellIndex>::iterator it = aMoves.begin();
    Board simulationBoard = *gameBoard; //Copy board

    while(it != aMoves.end()) {
        //simulate move
        simulationBoard.moveMade(*it, Player::getValue());


        ++it;
    }

    //Print
    cout << "Mmm... Let me think..." << endl;

    sleep(USING_BOARD->getAvailableSlots() * 500);


}


