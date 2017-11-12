/*
 * Project: Ex2
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
Player::Player(): value(BLACK){}

/*
 * Player(Cell c) Constructor.
 */
Player::Player(Cell c): value(c){}

/*
 * getValue().
 *
 * return Cell -- the color of the player
 */
Cell Player::getValue() const{
    return value;
}