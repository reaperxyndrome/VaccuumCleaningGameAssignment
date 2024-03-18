#include "board.h"
using std::vector;
using std::cout;
using std::endl;

// TODO: initialize board
Board::Board(){
    board = new vector<vector<Cell>>(
        DEFAULT_BOARD_DIMENSION, 
        vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY)
    );
}

Board::~Board(){
    delete board;
}

void Board::reset(){
    for (int i = 0; i < DEFAULT_BOARD_DIMENSION; i++){
        for (int j = 0; j < DEFAULT_BOARD_DIMENSION; j++){
            board->at(i).at(j) = EMPTY;
        }
    }
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

bool Board::placePlayer(Position position){
    if (position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION || 
        position.y < 0 || position.y >= DEFAULT_BOARD_DIMENSION){
        return false;
    }
    if (board->at(position.y).at(position.x) == BLOCKED){
        return false;
    }
    board->at(position.y).at(position.x) = PLAYER;
    return true;
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
            } else if (board->at(i-1).at(j-1) == PLAYER){
                player->displayDirection();
            }
        }
        cout << LINE_OUTPUT << endl;
    }
    cout << endl;
}

PlayerMove Board::movePlayerForward(Player* player){
    Position nextPosition = player->getNextForwardPosition();
    PlayerMove player_move = PLAYER_MOVED;
    if (nextPosition.x < 0 || nextPosition.x >= DEFAULT_BOARD_DIMENSION || 
        nextPosition.y < 0 || nextPosition.y >= DEFAULT_BOARD_DIMENSION){
        player_move = OUTSIDE_BOUNDS;
    }
    else if (board->at(nextPosition.y).at(nextPosition.x) == BLOCKED){
        player_move = CELL_BLOCKED;
    }
    if (player_move == PLAYER_MOVED){
        Position currentPosition = player->position;
        board->at(currentPosition.y).at(currentPosition.x) = EMPTY;
        player->updatePosition(nextPosition);
        placePlayer(nextPosition);
    }
    return player_move;
}