/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 *
 */

#ifndef BOARD_H_
#define BOARD_H_

//----------INCLUDING----------
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Cell.h"
#include "GameUtilities.h"

using namespace std;

//----------DEFINITIONS----------
#define BOARD this->board
#define CI CellIndex.index

//----------CONSTANTS----------
int const SMALL_BOARD_SIZE 		= 6;
int const DEFAULT_BOARD_SIZE 	= 8;
int const LARGE_BOARD_SIZE 		= 10;

//----------ENUMS----------
enum BoardType { sixBySix = 1, eightByEight, tenByTen };

class Board {
public:
    //Initializer
    Board(int boardType);
    //Destructor
    ~Board();

    //----------PUBLIC FUNCTIONS----------
    //Getters
    int 				getSpaceLeft();
    vector<CellIndex> 	getCellsInUse();
    Cell 				getBoardCell(int row, int col);
    int					getSize();
    int                 getAvailableSlots();
    Board*              getBoard();

    //Setters
    void                setCell(int row, int col, Cell val);

    //Printing
    void 				printBoard();

    //In-game use
    vector<CellIndex> 	getEmptyNeighbors(CellIndex cI);
    void				moveMade(CellIndex cI, Cell value);
    vector<CellIndex>	getCellPotentialAsVector(CellIndex cI, Cell type);
    int*                evaluateFinalScore();

    //Utility
    bool 				cellOnBoard(int row, int col);
    void 				clearBoard();

private:
    //----------VARIABLES----------
    int 				size;
    Cell** 				board;
    vector<CellIndex> 	cellsInUse;

    //----------PRIVATE FUNCTIONS----------
    //Initialization
    void 				initializeBoard();
    void 				initializeStartingCellValues();
    int 				defineBoardSize(int boardType);
    //Utility
    string 				generateCellValue(Cell c);
    vector<CellIndex> 	findPotentialInPath(CellIndex cI, int dRow,
                                             int dCol, Cell type);
    void 				changeCellColor(CellIndex cI);
    //Printing
    void 				printColsNumbers();
    void 				printSaparatingLine();
};

#endif /* BOARD_H_ */