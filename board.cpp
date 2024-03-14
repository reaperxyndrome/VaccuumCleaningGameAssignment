#include "board.h"
using std::vector;
using std::cout;
using std::endl;

// TODO: initialize board
Board::Board(){
    board = new vector<vector<Cell>>(DEFAULT_BOARD_DIMENSION, vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

const vector<vector<Cell>> Board::BOARD_1 = {
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY},
    {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}
    // Add more rows as needed
};

const vector<vector<Cell>> Board::BOARD_2 = {
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY,EMPTY},
    {EMPTY,BLOCKED,BLOCKED,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,BLOCKED,BLOCKED,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY},
    {EMPTY,BLOCKED,BLOCKED,EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY,BLOCKED,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,BLOCKED,EMPTY},
    {EMPTY,BLOCKED,BLOCKED,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
    {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY}
};

void Board::load(int boardId){
    if (boardId == 1){
        *board = BOARD_1;
    } else if (boardId == 2){
        *board = BOARD_2;
    }
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