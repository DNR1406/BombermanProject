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
void PlayerMovement::clear()
{
    int x = 120 + (this->x * 21);
    int y = 35 + (this->y * 21);
    lcd.drawCircle(x, y, 7, RGB(30, 107, 7));
    lcd.fillCircle(x, y, 7, RGB(30, 107, 7));
}

//Draws nethis->xt player location
void PlayerMovement::draw()
{
    int x = 120 + (this->x * 21);
    int y = 35 + (this->y * 21);
    lcd.fillCircle(x, y, 7, RGB(0, 0, 255));
}

//PLayer moves to the left
void PlayerMovement::left()
{
    //oude stip weg
    clear();

    this->x--;

    //nieuwe stip kleuren
    draw();
}

//zelfde functie als left, alleen voor right
void PlayerMovement::right()
{
    clear();

    this->x++;

    draw();
}

//zelfde functie als left, alleen voor down
void PlayerMovement::down()
{
    clear();

    this->y++;

    draw();
}

//zelfde functie als left, alleen voor up
void PlayerMovement::up()
{
    clear();

    this->y --;

    draw();
}