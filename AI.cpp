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

//----------INCLUDING---------
#include "AI.h"
#include "MovesEvaluator.h"

//----------INITIALIZER-LIST----------
/*
 * AI(Cell c, Board* gb) Constructor.
 *
 * @param gb Board -- the game's board
 */
AI::AI(Board* gameBoard): Player(WHITE, gameBoard) {}

//----------PUBLIC FUNCTIONS----------
/*
 * makeMove().
 *
 * @return string -- a raw string of player's move
 */
CellIndex AI::makeAMove(vector<CellIndex> availableMoves) const {
    //Local Variables
    Board* simulationBoard;
    vector<CellIndex>::iterator it = availableMoves.begin();
    CellIndex bestMove = { -1, -1 };

    //Inner-Loop Local Variables
    int minPotential = INT_MAX;

    //This loop is for simulating AI moves
    while(it != availableMoves.end()) {
        //Get a new Simulation Board
        simulationBoard = gameBoard->getBoard(); //Copy board
        //Simulate move
        simulationBoard->moveMade(*it, AI_COLOR);

        //for simulated move, evaluate moves for Player's turn
        vector<CellIndex> simAvailableMoves =
                MovesEvaluator::
                    evaluateAvailableMoves(gameBoard, PLAYER_COLOR);

        //find potential for ALL Player's moves
        int potential = calculatePotential(simulationBoard, simAvailableMoves);

        //Look for the minimal player potential for best AI move
        if(potential < minPotential) {
            //set new minPotential and bestMove
            minPotential = potential;
            bestMove = (*it);
        }

        ++it; //advance
    }

    //Print
    cout << "Mmm... Let me think..." << endl;

    //sleep((unsigned int) USING_BOARD->getAvailableSlots());

    return bestMove;
}


//----------PRIVATE FUNCTIONS----------
/*
 * calculatePotential(Board* gb, vector<CellIndex> vec) const.
 *
 * @param gb Board* -- a game board.
 * @vec vector<CellIndex> -- vector of moves
 *
 * @return the potential for the WHOLE vector moves
 */
int AI::calculatePotential(Board* gb, vector<CellIndex> vec) const {
    //Local Variables
    vector<CellIndex>::const_iterator it2 = vec.begin();
    int potential = 0;

    //This loop is for evaluating player's potential for each AI move
    while(it2 != vec.end()) {
        //simulate move
        gb->moveMade(*it2, PLAYER_COLOR);

        //for each cell in CellsInUse, check state for black and white
        vector<CellIndex>::const_iterator it3 =
                gb->getCellsInUse().begin();

        //Count the potential
        while(it3 != gb->getCellsInUse().end()) {
            //Inner-Loop Local Variables
            Cell boardCell =
                    gb->getBoardCell((*it3).index[0],
                                     (*it3).index[1]);

            if(boardCell == PLAYER_COLOR) { ++potential; }

            ++it3; //advance to next
        }
        ++it2; //advance
    }

    return potential;
}