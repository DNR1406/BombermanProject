#include <stdlib.h>
#include <Arduino.h>
#include <stdint.h>

#include "include.h"

Communication::Communication(int x, int y)
{
    //locatie player1, geen bom
    this->xPlayer1 = x;
    this->yPlayer1 = y;
    this->bombPlayer1 = 0;
    //locatie player2, geen bom
    this->xPlayer2 = x;
    this->yPlayer2 = y;
    this->bombPlayer2 = 0;
}

//player1
void Communication::setLocationPlayer1(int x, int y)
{
    this->setLocationPlayer1(x, y, 0);
}

void Communication::setLocationPlayer1(int x, int y, int bomb)
{
    this->xPlayer1 = x;
    this->yPlayer1 = y;
    this->bombPlayer1 = bomb;
}

void Communication::sendLocationPlayer1()
{
    Serial.println(String(this->xPlayer1) + String(this->yPlayer1) + String(this->bombPlayer1));
}

//player2
void Communication::getLocationPlayer2(int *x, int *y, int *bomb)
{
    *x = this->xPlayer2;
    *y = this->yPlayer2;
    *bomb = this->bombPlayer2;
}


void Communication::receiveLocationPlayer2()
{
    if (Serial.available())
    {
        char buffer[3];

        int x, y, bomb;

        Serial.readBytes(buffer, 3);
        x = buffer[0] - '0';
        y = buffer[1] - '0';
        bomb = buffer[2] - '0';

        this->xPlayer2 = (x > 0) ? x : this->xPlayer2;
        this->yPlayer2 = (y > 0) ? y : this->yPlayer2;
        this->bombPlayer2 = (bomb > 0) ? bomb : this->bombPlayer2;
    }
}

//other
void Communication::sendReceive()
{
    this->receiveLocationPlayer2();
    this->sendLocationPlayer1();
}






















// ------------------------------------------------------------------------------------

//  String incomming = Serial.readString();
//         int x = incomming[0] - '0';
//         int y = incomming[1] - '0';

//         if( x > 0) {
//             this->xPlayer2 = x;
//         }

//         if(y > 0) {
//             this->yPlayer2 = x;
//         }