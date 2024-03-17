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

bool Game::loadBoard()
{
    //TODO

    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{
     //TODO
}
