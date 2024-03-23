#ifndef GAME_H
#define GAME_H

#include "helper.h"
#include "board.h"
#include "player.h"

// strings used for input validation
#define COMMAND_LOAD "load"
#define COMMAND_INIT "init"
#define COMMAND_FORWARD "forward"
#define COMMAND_FORWARD_SHORTCUT "f"
#define COMMAND_TURN_LEFT "turn_left"
#define COMMAND_TURN_LEFT_SHORTCUT "l"

#define COMMAND_TURN_RIGHT "turn_right"
#define COMMAND_TURN_RIGHT_SHORTCUT "r"
#define COMMAND_QUIT "quit"
#define COMMAND_GENERATE_RANDOM "generate"

#define BLOCKED_MOVE_OUTPUT "There is a block in front of you. Try another move."
#define VALID_MOVE_OUTPUT "Move is valid."
#define OUTSIDE_BOUNDS_OUTPUT "The vacuum cleaner is at the edge of the board and cannot move further in that direction"

#define DIRECTION_NORTH "north"
#define DIRECTION_EAST "east"
#define DIRECTION_SOUTH "south"
#define DIRECTION_WEST "west"

class Game
{
private:

    Board* board;
    Player* player;


    /**
     * Load the board. 
     * Input options for the board loading are: 1 and 2
     */
    void loadBoard();
    
    /**
     * Initialize the player. 
     * Return command "quit" for quiting the game.
     */
    std::string initializePlayer();

    /**
     * Play the game and move the player interactively.
     * Return command "quit" for quiting the game.
     */
    std::string play();

    void handleLoadCommand(std::string* command, bool initializePlayer);

    void handleInitCommand(std::string* command);


public:

    // initialize and destroy the member variables
    Game();
    ~Game();

    /**
     * Main menu option 1 - play the game as per the specification.
     *
     * This method should call other methods in this class in the following order:
     * - loadBoard()
     * - initilizePlayer()
     * - play() 
     * 
     * These methods should in turn make all the calls to methods in board & player 
     * objects and handle interaction with the user (reading inputs from the console,
     * error checking, etc...).
     */
    void start();
};


#endif
