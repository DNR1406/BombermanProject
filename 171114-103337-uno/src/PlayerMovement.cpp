#include "PlayerMovement.h"
#include "include.h"
// Constructor

PlayerMovement::PlayerMovement(int x, int y)
{
    //begin waardes, secs, this->x, this->y
    this->x = x;
    this->y = y;
    this->leftMove = false;
    this->rightMove = true;
    this->upMove = false;
    this->downMove = true;
}

// Clears current player location
void PlayerMovement::clearPlayer()
{
    int x = 120 + (this->x * 21);
    int y = 35 + (this->y * 21);
    lcd.fillCircle(x, y, 7, RGB(29, 79, 22));
}

//Draws nethis->xt player location
void PlayerMovement::draw()
{
    int x = 120 + (this->x * 21);
    int y = 35 + (this->y * 21);
    lcd.fillCircle(x, y, 7, RGB(14, 44, 135));
}

//PLayer moves to the left
void PlayerMovement::left(uint8_t bombPlaced)
{
    if (!bombPlaced)
    {
        clearPlayer();
    }
    this->x--;
    draw();
}

//zelfde functie als left, alleen voor right
void PlayerMovement::right(uint8_t bombPlaced)
{
    if (!bombPlaced)
    {
        clearPlayer();
    }
    this->x++;
    draw();
}

//zelfde functie als left, alleen voor down
void PlayerMovement::down(uint8_t bombPlaced)
{
    if (!bombPlaced)
    {
        clearPlayer();
    }
    this->y++;
    draw();
}

//zelfde functie als left, alleen voor up
void PlayerMovement::up(uint8_t bombPlaced)
{
    if (!bombPlaced)
    {
        clearPlayer();
    }
    this->y--;
    draw();
}

uint8_t PlayerMovement::getXLocation() {
    return this->x;
}

uint8_t PlayerMovement::getYLocation() {
     return this->y;
}