#include <stdlib.h>
#include <Arduino.h>
#include <stdint.h>

#include "include.h"

Communication::Communication(int x, int y)
{
    this->xPlayer1 = x;
    this->yPlayer1 = y;

    Serial.begin(9600);
}

//player1
void Communication::setLocationPlayer1(int x, int y)
{
    this->xPlayer1 = x;
    this->yPlayer1 = y;
}

void Communication::setLocationPlayer1(int x, int y, int bomb)
{
}

void Communication::sendLocationPlayer1()
{
    Serial.println(String(this->xPlayer1) + String(this->yPlayer1));
}

//player2
int Communication::getLocationPlayer2(int *x, int *y)
{
    *x = this->xPlayer2;
    *y = this->yPlayer2;

    return 1;
}

int Communication::getLocationPlayer2(int *x, int *y, int *bomb)
{

    return 0;
}

void Communication::receiveLocationPlayer2()
{
    if (Serial.available())
    {
        char buffer[2];

        int x, y;

        Serial.readBytes(buffer, 2);
        x = buffer[0] - '0';
        y = buffer[1] - '0';

        this->xPlayer2 = (x > 0) ? x : this->xPlayer2;

        this->yPlayer2 = (y > 0) ? y : this->yPlayer2;
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