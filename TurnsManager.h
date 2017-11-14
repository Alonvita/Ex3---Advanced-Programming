/*
 * Project: Ex3
 * Author: Alon Vita
 * ID: 311233431
 *
 * TurnsManager Class.
 *
 * The TurnsManager class is in charge of everything that is linked to the
 *  turns of the games: availability, turn validity and who's turn it is.
 */

#ifndef TURNSMANAGER_H_
#define TURNSMANAGER_H_

//----------INCLUDING----------
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include "Board.h"
#include "Cell.h"
#include "GameUtilities.h"
#include "Participant.h"
#include "AI.h"

//----------DEFINITIONS----------
#define PLAYER this->players.at(playerTurn)

using namespace std;


class TurnsManager {
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializer
    TurnsManager();
    //Destructor
    ~TurnsManager();

    //Getters & Setters
    vector<CellIndex>	getAvailableMoves();
    void				addCellToAvailableMoves(CellIndex cI);
    Cell				getCurrentPlayerColor();

    //Utilities
    void 				endTurn();
    void 				evaluateAvailableMovesForThisTurn(Board* gb);
    CellIndex 			playerMove(int boardSize);

private:
    //----------VARIABLES----------
    bool 				    playerTurn;
    vector<Player*> 		players;
    vector<CellIndex>	    availableMoves;

    //----------PRIVATE FUNCTIONS----------
    //Initializers
    void	 			initializeTwoParticipants();
    void                initializeParticipantAndAI(Board* gameBoard);

    //Utilities
    string 				callPlayerByName();
    bool 				isMoveLegal(CellIndex cI);
    vector<string> 		stringToVector(string str);
    CellIndex 			stringToPlayerMove(string rawString, int boardSize);
    //Printing
    void				printAvailableMoves();
};

#endif /* TURNSMANAGER_H_ */