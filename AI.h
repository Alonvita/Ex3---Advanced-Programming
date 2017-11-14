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
#include "Cell.h"
#include "Player.h"

using namespace std;

class AI : public Player{
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializers
    explicit            AI(Board* gameBoard);

    //In-Game Usage
    virtual string       makeAMove() const;
};

#endif /* AI_H_ */