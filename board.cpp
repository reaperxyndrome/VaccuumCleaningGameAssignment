#include "board.h"
using std::vector;
using std::cout;
using std::endl;

// TODO: initialize board
Board::Board(){
    board = new vector<vector<Cell>>(DEFAULT_BOARD_DIMENSION, vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

Board::~Board(){
    delete board;
}

void Board::display(Player* player){
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION+1; i++){
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION+1; j++){
            cout << LINE_OUTPUT;

            if (i == 0){
                if(j == 0){
                    cout << EMPTY_OUTPUT;
                }
                else{
                    cout << j-1;
                }
            } else if (j == 0){
                cout << i-1;
            } else if (board->at(i-1).at(j-1) == EMPTY){
                cout << EMPTY_OUTPUT;
            } else if (board->at(i-1).at(j-1) == BLOCKED){
                cout << BLOCKED_OUTPUT;
            }
        }
        cout << LINE_OUTPUT << endl;
    }
    cout << endl;
}