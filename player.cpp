#include "player.h"

using std::cout;

Position::Position()
{
    x = 0;
    y = 0;
}


Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Player::Player()
{
    position = Position();
    moves = 0;

}

void Player::initialisePlayer(Position* position, Direction direction)
{
    this->position = *position;
    this->direction = direction;
    moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
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
    Position newPosition = Position();
    if(this->direction == NORTH){
        newPosition = Position(this->position.x, this->position.y - 1);
    } else if(this->direction == EAST){
        newPosition = Position(this->position.x + 1, this->position.y);
    } else if(this->direction == SOUTH){
        newPosition = Position(this->position.x, this->position.y + 1);
    } else if(this->direction == WEST){
        newPosition = Position(this->position.x - 1, this->position.y);
    }

    return newPosition;
}

void Player::updatePosition(Position position)
{
    this->position = getNextForwardPosition();
    ++moves;
}

void Player::displayDirection()
{
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
