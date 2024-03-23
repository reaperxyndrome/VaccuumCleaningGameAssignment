#include "game.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

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
    // Display all game commands to the user
    Helper::showAllGameCommands();
    cout << "Press enter or space to continue..." << endl;

    // Wait for user input (enter or space) to continue
    string input;
    cin.ignore();
    
    board->reset(); // Reset the game board to its initial state
    cout << "The game board is displayed below: " << endl << endl;
    board->display(player); // Display the current state of the game board

    // Show the game commands available when the board is empty
    Helper::showGameCommandsEmpty();

    // Load the game board with the initial game setup
    Game::loadBoard();
}

void Game::loadBoard(){
    string command = " ";
    // Loop until the user enters the quit command
    while (command != COMMAND_QUIT){
        cin >> command;   
        // If the user enters the load command
        if (command == COMMAND_LOAD){
            handleLoadCommand(&command, true);
        } 
        // If the user enters an invalid command
        else {
            if (command != COMMAND_QUIT){
                // Print an error message and show the commands available when the board is empty
                Helper::printInvalidInput();
                Helper::showGameCommandsEmpty();
            }
        }
    }
}

void Game::handleLoadCommand(std::string* command, bool initializePlayer){
    string boardId;
    cin >> boardId;
    bool boardIdValid = Helper::isNumber(boardId) && 
                        (boardId == "1" || boardId == "2");
    if (boardIdValid){
        board->load(stoi(boardId));
        cout << "The game board is displayed below: " << endl << endl;
        board->display(player);
        Helper::showGameCommandsLoaded();
        if (initializePlayer){
            *command = this->initializePlayer();
        }
    }
    else {
        Helper::printInvalidInput();
        Helper::showGameCommandsLoaded();   
    }
}

std::string Game::initializePlayer(){
    string command = " ";
    while (command != COMMAND_QUIT){
        cin >> command;
        if (command == COMMAND_LOAD){
            handleLoadCommand(&command, false);
        } else if (command == COMMAND_INIT) {
            string init_input = Helper::readInput();
            vector<string> tokens;
            Helper::splitString(init_input, tokens, ",");
            if(tokens.size() == 3){
                string x = tokens[0];
                string y = tokens[1];
                string direction = tokens[2];
                // cin.getline()
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
                    bool success = board->placePlayer(position);
                    if (success){
                        board->display(player);
                        Helper::showGameCommandsInitialized();
                        command = play();
                    }
                    else{
                        Helper::printInvalidInput();
                        Helper::showGameCommandsLoaded();
                    }
                }
                else{
                    Helper::printInvalidInput();
                    Helper::showGameCommandsLoaded();
                }
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

void Game::handleInitCommand(std::string* command){
    string init_input = Helper::readInput();
    vector<string> tokens;
    Helper::splitString(init_input, tokens, ",");
    if(tokens.size() == 3){
        string x = tokens[0];
        string y = tokens[1];
        string direction = tokens[2];
        // cin.getline()
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
            bool success = board->placePlayer(position);
            if (success){
                board->display(player);
                Helper::showGameCommandsInitialized();
                *command = play();
            }
            else{
                Helper::printInvalidInput();
                Helper::showGameCommandsLoaded();
            }
        }
        else{
            Helper::printInvalidInput();
            Helper::showGameCommandsLoaded();
        }
    }
}

std::string Game::play()
{
    //TODO: debug why movePlayerForward is not working
    string command = " ";
    while (command != COMMAND_QUIT){
        cin >> command;
        if (command == COMMAND_FORWARD || command == COMMAND_FORWARD_SHORTCUT){
            PlayerMove move = board->movePlayerForward(player);
            if (move == PLAYER_MOVED){
                cout << VALID_MOVE_OUTPUT << endl;
                board->display(player);
            } else if (move == CELL_BLOCKED){
                cout << BLOCKED_MOVE_OUTPUT << endl;
                board->display(player);
            } else if (move == OUTSIDE_BOUNDS){
                cout << OUTSIDE_BOUNDS_OUTPUT << endl;
                board->display(player);
            }
        } else if (command == COMMAND_TURN_LEFT || command == COMMAND_TURN_LEFT_SHORTCUT){
            player->turnDirection(TURN_LEFT);
            board->placePlayer(player->position);
            board->display(player);
        } else if (command == COMMAND_TURN_RIGHT || command == COMMAND_TURN_RIGHT_SHORTCUT){
            player->turnDirection(TURN_RIGHT);
            board->placePlayer(player->position);
            board->display(player);
        } else {
            if (command != COMMAND_QUIT){
                Helper::printInvalidInput();
                Helper::showGameCommandsInitialized();
            }
        }
        
    }
    cout << "Total player moves: " << player->moves << endl;
    return command;
}

