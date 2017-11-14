/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 * TurnsManager Class.
 *
 * The TurnsManager class is in charge of everything that is linked to the
 *  turns of the games: availability, turn validity and who's turn it is.
 */

//----------INCLUDING----------
#include "TurnsManager.h"

//----------Initialization list----------
/*
 * TurnsManager() Constructor.
 */
TurnsManager::TurnsManager(): playerTurn(0) {
    initializeTwoParticipants();
}

//----------DESTRUCTORS----------
/*
 * ~TurnsManager().
 */
TurnsManager::~TurnsManager() {
    //Remove both players
    vector<Player*> vec;
    players.swap(vec);
}

//----------GETTERS & SETTERS----------

/*
 * getAvailableMovesNum().
 *
 * @return int -- the number of available moves for this turn.
 */
int TurnsManager::getAvailableMovesNum() {
    return (int) availableMoves.size();
}

/*
 * getCurrentPlayerColor().
 *
 * @return Cell -- current playing player's color
 */
Cell TurnsManager::getCurrentPlayerColor() {
    return ((Cell)this->playerTurn);
}

//----------Public Functions----------
/*
 * addCellToAvailableMoves(cI CellIndex).
 *
 *@param cI CellIndex -- a struct that holds a cell's index as [row,col].
 */
void TurnsManager::addCellToAvailableMoves(CellIndex cI) {
    this->availableMoves.push_back(cI);
}

/*
 * endTurn().
 *
 * This function will XOR the current player turn with 1 so that the turn is
 *  passed on to the next player.
 */
void TurnsManager::endTurn() {
    this->playerTurn = this->playerTurn ^ 1;
}


/*
 * evaluateAvailableMovesForThisTurn(Board* gb).
 *
 * @param gb Board* -- the game's board.
 */
void TurnsManager::evaluateAvailableMovesForThisTurn(Board* gb) {
    //clear last turn's availableMoves, get new moves and shrink
    availableMoves.clear();
    availableMoves = MovesEvaluator::evaluateAvailableMoves(gb, (Cell)playerTurn);
    availableMoves.shrink_to_fit();

    //Print
    cout << callPlayerByName() << " player: it's your move." << endl;
    printAvailableMoves();
}

/*
 * playerMove(int boardSize).
 *
 * @param boardSize int -- the board's size
 *
 * @return CellIndex* -- a reference to the move made as string holding a cell
 *  					 index as [row,col].
 */
CellIndex TurnsManager::playerMove(int boardSize) {
    //Local Variables
    CellIndex playerMove;

    do {
        playerMove = (*PLAYER).makeAMove(availableMoves);
    } while(!isMoveLegal(playerMove));

    return playerMove;
}

//----------INITIALIZATION FUNCTIONS----------
/*
 * initializeTwoParticipants().
 */
void TurnsManager::initializeTwoParticipants() {
    players.push_back(new Participant(WHITE));
    players.push_back(new Participant(BLACK));
}

/*
 * initializeParticipantAndAI().
 */
void TurnsManager::initializeParticipantAndAI(Board* gb) {
    players.push_back(new AI(gb));
    players.push_back(new Participant(BLACK));
}

//----------PRIVATE FUNCTIONS----------
/*
 * callPlayerByName().
 *
 * @return string -- a representation of player's name.
 */
string TurnsManager::callPlayerByName() {
    if(this-> playerTurn == WHITE) {
        return "(\"O\") White";
    }

    return "(\"X\") Black";
}

/*
 * printAvailableMoves().
 */
void TurnsManager::printAvailableMoves() {
    //Local Variables
    vector<CellIndex>::iterator it = this->availableMoves.begin();

    //Print
    cout << "Your possible moves are: ";

    //Itter over available moves and print them
    while(it != this->availableMoves.end()) {
        cout << "(" << (*it).index[0] + 1 << "," << (*it).index[1] + 1 << ")";
        if(it != this->availableMoves.end() - 1) {
            cout << ",";
        }
        ++it;
    }
    cout << endl;
}

/*
 * isMoveLegal(CellIndex cI).
 *
 * @param cI CellIndex -- a reference to struct holding cell's index
 * 						   as [row,col]
 *
 * @return true if the move is legal or false otherwise.
 */
bool TurnsManager::isMoveLegal(CellIndex cI) {
    //Check { -1,-1 } for bad input
    if(cI.index[0] == -1 && cI.index[1] == -1) {
        cout << "This move is illegal" << endl;
        return false;
    }

    int playerMoveRow = (cI).index[0];
    int playerMoveCol = (cI).index[1];
    vector<CellIndex>::iterator it = this->availableMoves.begin();

    while(it != this->availableMoves.end()) {
        //Inner-Loop Variables
        int availableMoveRow = (*it).index[0];
        int availableMoveCol = (*it).index[1];

        //Check is the player's move matches any available moves
        if(playerMoveRow == availableMoveRow
           && playerMoveCol == availableMoveCol) {
            return true;
        }
        ++it; //Advance iterator
    }

    cout << "This move is illegal" << endl;
    return false;
}