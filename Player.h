/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * Player Class.
 *
 * Players will hold their own values and make moves as raw strings. Those
 *  strings will be managed by the TurnsManager.
 *
 */

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

//----------INCLUDES----------
#include "Board.h"
#include "Cell.h"

class Player {
//----------PUBLIC CLASSES----------
public:
    //Initializer
    Player();
    explicit            Player(Cell c);
    explicit            Player(Cell c, Board* gb);

    //In-Game Usage
   virtual CellIndex    makeAMove(vector<CellIndex> aMoves) const = 0;

    //Getters & Setters
    Cell                getValue() const;

//----------PRIVATE CLASSES----------
private:
    Cell                value;
protected:
    Board*              gameBoard;
};

#endif //UNTITLED_PLAYER_H
