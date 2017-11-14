/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * Participant Class.
 *
 * A Participant is an out side user.
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_

//----------INCLUDING----------
#include <string>
#include <iostream>
#include "Cell.h"
#include "Player.h"

using namespace std;

class Participant : public Player {
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializers
    explicit            Participant(Cell c);

    //In-Game Usage
    virtual string       makeAMove() const override;
};

#endif /* PLAYER_H_ */