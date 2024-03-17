#include "game.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game()
{
    board = new Board();
    player = new Player();
}

Game::~Game()
{
    delete board;
    delete player;
}


void Game::start()
{
    Helper::showAllGameCommands();
    cout << "Press enter or space to continue..." << endl;

    string input;
    cin.ignore();
    
    board->reset();
    cout << "The game board is displayed below: " << endl << endl;
    board->display(player);
    Helper::showGameCommandsEmpty();
    // menuInputEmpty(&board, &player);

    Game::loadBoard();
}

void Game::loadBoard(){
    string command = " ";
    while (command != COMMAND_QUIT){
        cin >> command;   
        if (command == COMMAND_LOAD){
            string boardId;
            cin >> boardId;
            bool boardIdValid = Helper::isNumber(boardId) && 
                                (boardId == "1" || boardId == "2");
            if (boardIdValid){
                board->load(stoi(boardId));
                cout << "The game board is displayed below: " << endl << endl;
                board->display(player);
                Helper::showGameCommandsLoaded();
                command = initializePlayer();
            }
            else{
                Helper::printInvalidInput();
                Helper::showGameCommandsEmpty();   
            }
        } else {
            if (command != COMMAND_QUIT){
                Helper::printInvalidInput();
                Helper::showGameCommandsEmpty();
            }
        }
    }
}

std::string Game::initializePlayer(){
    string command = " ";
    while (command != COMMAND_QUIT){
        cin >> command;
        if (command == COMMAND_LOAD){
            string boardId;
            cin >> boardId;
            bool boardIdValid = Helper::isNumber(boardId) && 
                                (boardId == "1" || boardId == "2");
            if (boardIdValid){
                board->load(stoi(boardId));
                cout << "The game board is displayed below: " << endl << endl;
                board->display(player);
                Helper::showGameCommandsLoaded();
            }
            else {
                Helper::printInvalidInput();
                Helper::showGameCommandsLoaded();   
            }
            // TODO: fix initialization (input)
        } else if (command == COMMAND_INIT) {
            string x, y, direction;
            cin >> x >> y >> direction;
            cin.getline()
            bool xValid = Helper::isNumber(x) && stoi(x) >= 0 && stoi(x) < DEFAULT_BOARD_DIMENSION;
            bool yValid = Helper::isNumber(y) && stoi(y) >= 0 && stoi(y) < DEFAULT_BOARD_DIMENSION;
            bool directionValid = direction == DIRECTION_NORTH || direction == DIRECTION_EAST || 
                                direction == DIRECTION_SOUTH || direction == DIRECTION_WEST;
            if (xValid && yValid && directionValid){
                Position position = Position(stoi(x), stoi(y));
                if(direction == DIRECTION_NORTH){
                    player->initialisePlayer(&position, NORTH);
                } else if(direction == DIRECTION_EAST){
                    player->initialisePlayer(&position, EAST);
                } else if(direction == DIRECTION_SOUTH){
                    player->initialisePlayer(&position, SOUTH);
                } else if(direction == DIRECTION_WEST){
                    player->initialisePlayer(&position, WEST);
                }
                cout << "The game board is displayed below: " << endl << endl;
                board->display(player);
                Helper::showGameCommandsLoaded();
                return COMMAND_FORWARD;
            }
            else {
                Helper::printInvalidInput();
                Helper::showGameCommandsLoaded();
            }
        }
        else {
            if (command != COMMAND_QUIT){
                Helper::printInvalidInput();
                Helper::showGameCommandsLoaded();
            }
        }
    }
    return command;
}

void Game::play()
{
     //TODO
}

