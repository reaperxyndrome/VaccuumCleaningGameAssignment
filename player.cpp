#include "player.h"

using std::cout;

Position::Position()
{
    //TODO
    x = 0;
    y = 0;
}


Position::Position(int x, int y)
{
    //TODO
    this->x = x;
    this->y = y;
}

Player::Player()
{
    //TODO
    position = Position();

}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
    this->position = *position;
    this->direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
    if(turnDirection == TURN_RIGHT){
        if(direction == NORTH) direction = EAST;
        else if(direction == EAST) direction = SOUTH;
        else if(direction == SOUTH) direction = WEST;
        else if(direction == WEST) direction = NORTH;
    } else if(turnDirection == TURN_LEFT){
        if(direction == NORTH) direction = WEST;
        else if(direction == WEST) direction = SOUTH;
        else if(direction == SOUTH) direction = EAST;
        else if(direction == EAST) direction = NORTH;
    }
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //TODO
    if(this->direction == NORTH){
        cout << DIRECTION_ARROW_OUTPUT_NORTH;
    } else if(this->direction == EAST){
        cout << DIRECTION_ARROW_OUTPUT_EAST;
    } else if(this->direction == SOUTH){
        cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    } else if(this->direction == WEST){
        cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
}
