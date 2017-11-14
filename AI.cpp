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

//----------INITIALIZER-LIST----------
/*
 * AI(Cell c, Board* gb) Constructor.
 *
 * @param gb Board -- the game's board
 */
AI::AI(Board* gameBoard): Player(WHITE, gb){}

//----------PUBLIC FUNCTIONS----------
/*
 * makeMove().
 *
 * @return string -- a raw string of player's move
 */
string AI::makeAMove() const {
    
}
