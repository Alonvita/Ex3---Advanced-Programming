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
CellIndex Participant::makeAMove(vector<CellIndex> aMoves) const{
    //Local Variables
    string rawPlayerString;

    //Print
    cout << "Please make a move row,col:" << endl;

    cin >> rawPlayerString;

    return (stringToPlayerMove(rawPlayerString));
}

/*
 * stringToVector(string str).
 *
 * @param str string -- a string.
 *
 * @return vector<string> -- a vector holding the string broken to pieces,
 * 							 separated by the delimiter ','.
 */
vector<string> Participant::stringToVector(string str) const{
    istringstream ss(str);
    string token;
    vector<string> vec;

    while(std::getline(ss, token, ',')) {
        vec.push_back(token);
    }

    return vec;
}

/*
 * stringToPlayerMove(string rawString, int boardSize).
 *
 * @param rawString string -- a raw representation of a player's move.
 * @param boardSize int -- the gameboard's size
 *
 * @returm CellIndex -- a CellIndex represents the player's move.
 */
CellIndex Participant::stringToPlayerMove(string rawString) const {
    //Local Variables
    vector<string> stringAsVector = stringToVector(rawString);
    CellIndex retVal = { -1, -1 }; //Default value is out of bounds

    //First, check vector size
    if(stringAsVector.size() != 2) {
        return retVal;
    }

    //get row,col for player input -1 since we are working with an array.
    int row = atoi(stringAsVector.at(0).c_str()) - 1;
    int col = atoi(stringAsVector.at(1).c_str()) - 1;

    return { row , col };
}