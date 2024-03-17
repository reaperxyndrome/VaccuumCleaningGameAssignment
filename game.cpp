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
    
    cout << "The game board is displayed below: " << endl << endl;
    board->display(player);
    Helper::showGameCommandsEmpty();
    // menuInputEmpty(&board, &player);

    Game::loadBoard();
    Game::initializePlayer();
    Game::play();
}

void Game::loadBoard(){
    string command = " ";
    while (command != "quit"){
        cin >> command;   
        if (command == "load"){
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
            if (command != "quit"){
                Helper::printInvalidInput();
                Helper::showGameCommandsEmpty();
            }
        }
    }
}

std::string Game::initializePlayer(){
    string command = " ";
    while (command != "quit"){
        cin >> command;
        if (command == "load"){
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
        } else {
            if (command != "quit"){
                Helper::printInvalidInput();
                Helper::showGameCommandsLoaded();
            }
        }
    }
    return command;
}

// bool Game::initializePlayer()
// {
//     //TODO
//     return false; // feel free to revise this line.
// }

void Game::play()
{
     //TODO
}

