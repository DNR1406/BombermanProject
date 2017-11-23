#include "Communication.h"
#include <stdlib.h>
#include "Bomb.h"

Communication::Communication()
{
    //timer instellen
}

void Communication::setLocationPlayer1(int x, int y)
{
    this->xPlayer1 = x;
    this->yPlayer1 = y;
}

void Communication::getPositionPlayer2(int *x, int *y)
{
    *x = this->xPlayer2;
    *y = this->yPlayer2;
}

void Communication::setBombPlayer1(int x, int y) {
    this->bombPlayer2 = new Bomb(x, y);
}


void Communication::getBombPlayer2(Bomb *bomb) {
   *bomb = *this->bombPlayer2;
}

void Communication::removeBombPlayer1() {
    this->bombPlayer1 = NULL;
}

void Communication::removeBombPlayer2() {
    this->bombPlayer2 = NULL;
}