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

#ifndef AI_H_
#define AI_H_

//----------INCLUDING----------
#include <string>
#include <iostream>
#include <unistd.h>
#include "Cell.h"
#include "MovesEvaluator.h"
#include "Player.h"

//----------DEFINITIONS----------
#define USING_BOARD Player::gameBoard

using namespace std;

class AI : public Player, public MovesEvaluator {
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializers
    explicit            AI(Board* gameBoard);

    //In-Game Usage
    virtual CellIndex   makeAMove(vector<CellIndex> aMoves) const;
};

#endif /* AI_H_ */