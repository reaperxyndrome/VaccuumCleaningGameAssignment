#include "game.h"

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