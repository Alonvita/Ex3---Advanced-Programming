/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * Participant Class.
 *
 * A Participant is an outside user.
 */

#include "Participant.h"

//----------Initializer List----------
/*
 * Participant(Cell c) Constructor.
 *
 * @param c Cell -- participant's color
 */
Participant::Participant(Cell c): Player(c) {}

//----------Public Functions----------
/*
 * makeMove().
 *
 * @return string -- a raw string of player's move
 */
string Participant::makeAMove() const{
    //Local Variables
    string rawPlayerString;

    cin >> rawPlayerString;

    return rawPlayerString;
}