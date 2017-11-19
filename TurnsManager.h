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
#include <string>
#include "AI.h"
#include "Board.h"
#include "Cell.h"
#include "GameUtilities.h"
#include "MovesEvaluator.h"
#include "Participant.h"

//----------DEFINITIONS----------
#define PLAYER this->players.at(playerTurn)

using namespace std;


class TurnsManager: MovesEvaluator {
public:
    //----------PUBLIC FUNCTIONS----------
    //Initializer
    TurnsManager(int numPlayers, Board* gb);
    //Destructor
    ~TurnsManager();

    //Getters & Setters
    int	                getAvailableMovesNum();
    void				addCellToAvailableMoves(CellIndex cI);
    Cell				getCurrentPlayerColor();

    //Utilities
    void 				endTurn();
    CellIndex 			nextMove(int boardSize);

    //Nested Classes
    void evaluateAvailableMovesForThisTurn(Board *gb);
private:
    //----------VARIABLES----------
    bool 				    playerTurn;
    vector<Player*> 		players;
    vector<CellIndex>	    availableMoves;

    //----------PRIVATE FUNCTIONS----------
    //Initializers
    void	 			initializeTwoParticipants();
    void                initializeOneParticipant(Board* gb);

    //Utilities
    string 				callPlayerByName();
    bool 				isMoveLegal(CellIndex cI);

    //Printing
    void				printAvailableMoves();
};

#endif /* TURNSMANAGER_H_ */