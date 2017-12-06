#include "PlayerMovement.h"
// Constructor
PlayerMovement::PlayerMovement(int x, int y, int r, int g, int b)
{
    //begin waardes, secs, this->x, this->y
    this->x = x;
    this->y = y;
    //rgb van kleur
    this->r = r;
    this->g = g;
    this->b = b;
}

// Clears current player location
void PlayerMovement::clear()
{

    lcd.drawCircle(this->x, this->y, 8, RGB(30, 107, 7));
    lcd.fillCircle(this->x, this->y, 8, RGB(30, 107, 7));
}

//Draws nethis->xt player location
void PlayerMovement::draw()
{
    lcd.fillCircle(this->x, this->y, 8, RGB(r, g, b));
}

//PLayer moves to the left
void PlayerMovement::left()
{
    //oude stip weg
  this->clear();
  //x tien vanaf
  if(this->x > 100)
    this->x -= 10;
  //nieuwe stip kleuren
  this->draw();
}

//zelfde functie als left, alleen voor right
void PlayerMovement::right()
{
    clear();
    if (this->x < 312)
        this->x += 10;
    draw();
}

//zelfde functie als left, alleen voor down
void PlayerMovement::down()
{
    clear();
    if (this->y > 10)
        this->y += 10;
    draw();
}

//zelfde functie als left, alleen voor up
void PlayerMovement::up()
{
    clear();
    if (this->y < 228)
        this->y -=10;
    draw();
}