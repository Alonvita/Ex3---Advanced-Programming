/*
 * Project: Ex3.
 * Author: Alon Vita
 * ID: 311233431
 */
#include "Board.h"
#include "ReversiGame.h"

using namespace std;


/*
 * main().
 */
int main() {
    //Local Main Variables
    int boardType;

    cout << "Hello and welcome to my ReversiGame. Please choose a board type:"
         << endl << "1: 6x6" << endl << "2: 8x8 (also default)" << endl <<
         "3: 10x10" << endl;
    cin >> boardType;

    Board b(boardType);

    //create game with initialized board
    ReversiGame g(&b);
    g.startGame();
}