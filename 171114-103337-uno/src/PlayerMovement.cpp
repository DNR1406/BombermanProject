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

    lcd.drawCircle(this->x, this->y, 7, RGB(30, 107, 7));
    lcd.fillCircle(this->x, this->y, 7, RGB(30, 107, 7));
}

//Draws nethis->xt player location
void PlayerMovement::draw()
{
    lcd.fillCircle(this->x, this->y, 7, RGB(0,0,255));
}

//PLayer moves to the left
void PlayerMovement::left()
{
    //oude stip weg
    clear();
    //x tien vanaf
    if (this->x > 100)
        this->x -= 21;
    //nieuwe stip kleuren
    draw();
}

//zelfde functie als left, alleen voor right
void PlayerMovement::right()
{
    clear();
    if (this->x < 306)
        this->x += 21;
    draw();
}

//zelfde functie als left, alleen voor down
void PlayerMovement::down()
{
    clear();
    if (this->y > 10)
        this->y += 21;
    draw();
}

//zelfde functie als left, alleen voor up
void PlayerMovement::up()
{
    clear();
    if (this->y < 228)
        this->y -= 21;
    draw();
}