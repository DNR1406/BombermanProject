#include "PlayerMovement.hpp"
#include "Drawings.hpp"

// Constructor
PlayerMovement::PlayerMovement(uint8_t x, uint8_t y, uint8_t player)
{
    //begin waardes, secs, this->x, this->y
    this->x = x;
    this->y = y;
    this->leftMove = false;
    this->rightMove = true;
    this->upMove = false;
    this->downMove = true;
    this->player = player;
    this->lifes = 3;
}

// Clears current player location
void PlayerMovement::clearPlayer(uint8_t x, uint8_t y)
{
    deletePlayer(x, y);
}

//Draws nethis->xt player location
void PlayerMovement::draw(uint8_t player, uint8_t side)
{
    drawPlayer(this->x, this->y, side, player, 1);
}

//PLayer moves to the left
void PlayerMovement::left()
{

    this->x--;
}

//zelfde functie als left, alleen voor right
void PlayerMovement::right()
{

    this->x++;
}

//zelfde functie als left, alleen voor down
void PlayerMovement::down()
{

    this->y++;
}

//zelfde functie als left, alleen voor up
void PlayerMovement::up()
{
    this->y--;
}

uint8_t PlayerMovement::getXLocation()
{
    return this->x;
}

uint8_t PlayerMovement::getYLocation()
{
    return this->y;
}

uint8_t PlayerMovement::getLifes()
{
    return this->lifes;
}

uint8_t PlayerMovement::getScore()
{
    return this->score;
}

void PlayerMovement::setLifes(uint8_t lifes)
{
    this->lifes = lifes;

    // Putting leds out
    if (this->lifes == 2)
    {
        PORTB &= ~(1 << PORTB2);
    }
    else if (this->lifes == 1)
    {
        PORTD &= ~(1 << PORTD4);
    }
    else
    {
        // PORTD &= ~(1 << PORTD3);
    }
}

void PlayerMovement::setScore(uint8_t score)
{
    this->score = score;
}

void PlayerMovement::updateScore()
{
    if (this->player == 1)
    {
        lcd.drawInteger(62, 130, this->score, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
    }
    else
    {
        lcd.drawInteger(62, 230, this->score, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
    }
}

void PlayerMovement::updateLives()
{
    if (this->player == 1)
    {
        lcd.drawInteger(62, 120, this->lifes, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
    }
    else
    {
        lcd.drawInteger(62, 220, this->lifes, DEC, RGB(31, 255, 0), RGB(50, 50, 50), 1);
    }
}
