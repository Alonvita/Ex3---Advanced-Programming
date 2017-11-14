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

    this->players.swap(vec);
}

//----------Public Functions----------
/*
 * getAvailableMoves().
 *
 * @return vector<CellIndex> -- a vector with all current available moves.
 */
vector<CellIndex> TurnsManager::getAvailableMoves() {
    return this->availableMoves;
}

//----------GETTERS & SETTERS----------
/*
 * getCurrentPlayerColor().
 *
 * @return Cell -- current playing player's color
 */
Cell TurnsManager::getCurrentPlayerColor() {
    return ((Cell)this->playerTurn);
}

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
    //Local Variables
    vector<CellIndex> cellsInUse = gb->getCellsInUse();
    vector<CellIndex>::iterator it = cellsInUse.begin();

    //clear last turn's availableMoves
    this->availableMoves.clear();

    //Itter over cellsInUse
    while(it != cellsInUse.end()) {
        //Inner Loop Variables
        Cell currentCell = gb->getBoardCell((*it).index[0],(*it).index[1]);

        //Check if cell's value is OPPOSITE to the playing player's value
        if((currentCell == WHITE && playerTurn == BLACK)
           || (currentCell == BLACK && playerTurn == WHITE)) {
            //get cell's empty neighbors
            vector<CellIndex> emptyNeighbors = gb->getEmptyNeighbors(*it);
            vector<CellIndex>::iterator it = emptyNeighbors.begin();

            //For each neighbor -> check that it has potential
            while(it != emptyNeighbors.end()) {

                //create potential vector
                vector<CellIndex> cellPotential =
                        gb->getCellPotentialAsVector(*it, (Cell)playerTurn);

                //Cell has potential and therefore an available move!
                if(!cellPotential.empty()) {
                    //Reserve place for the vector
                    addCellToAvailableMoves(*it);
                }

                ++it;
            }
        }
        ++it;
    }
    //Clear Duplicates
    clearDuplicatesValues(&availableMoves);

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
    string playerMoveAsRawString;
    CellIndex playerMove;

    do {
        //Print
        cout << "Please make a move row,col:" << endl;

        playerMoveAsRawString = (*PLAYER).makeAMove();

        playerMove = stringToPlayerMove(playerMoveAsRawString, boardSize);

        //Scan move from player
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

/*
 * stringToVector(string str).
 *
 * @param str string -- a string.
 *
 * @return vector<string> -- a vector holding the string broken to pieces,
 * 							 saparated by the delimiter ','.
 */
vector<string> TurnsManager::stringToVector(string str) {
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
CellIndex TurnsManager::stringToPlayerMove(string rawString, int boardSize) {
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

    //if size is good, check validity
    if(0 <= row && row < boardSize && 0 <= col && col < boardSize) {
        //Change return value
        retVal.index[0] = row;
        retVal.index[1] = col;
        return retVal;
    }

    return retVal;
}