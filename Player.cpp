/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * Player Class.
 *
 * Players will hold their own values and make moves as raw strings. Those
 *  strings will be managed by the TurnsManager.
 */

//----------Initializer List----------

#include "Player.h"

/*
 * Player() Constructor.
 */
Player::Player(): value(BLACK) {
    this->gameBoard = nullptr;
}

/*
 * Player(Cell c) Constructor.
 *
 * @param c Cell - the player's color
 */
Player::Player(Cell c): value(c) {
    this->gameBoard = nullptr;
}

/*
 * Player(Cell c, Board* gb) Constructor.
 *
 * @param c Cell - the player's color
 * @param gb Board -- the game's board
 */
Player::Player(Cell c, Board* gb): value(c), gameBoard(gb) {}


/*
 * getValue().
 *
 * return Cell -- the color of the player
 */
Cell Player::getValue() const{
    return value;
}