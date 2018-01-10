// Includes
#include "Bomb.hpp"
#include "Globals.hpp"
#include "Drawings.hpp"
#include <Arduino.h>

Bomb::Bomb()
{
}

Bomb::Bomb(uint8_t x, uint8_t y, uint32_t startTime)
{
    this->lastXlocation = x;
    this->lastYlocation = y;
    this->lastKnownTime = startTime;
    this->exploded = 1;
}

// Wait 3 seconds for bomb countdown
uint8_t Bomb::checkDetonation(uint8_t barrels[9][9])
{
    if (this->lastKnownTime == 0)
    {
        return 0;
    }
    else
    {
        uint32_t bombTime = ((this->lastKnownTime + 35000) - counterTimer2);

       

        if (bombTime > 5000)
        {
            updateWick(this->lastXlocation, this->lastYlocation, bombTime);
        }
        else
        {
            explodeBomb(this->lastXlocation, this->lastYlocation, bombTime, barrels);
        }
        return ((this->lastKnownTime + 35000) < counterTimer2);
    }
}

void Bomb::setXlocation(uint8_t x)
{
    this->lastXlocation = x;
}

uint8_t Bomb::returnXlocation()
{
    return this->lastXlocation;
}

void Bomb::setYlocation(uint8_t y)
{
    this->lastYlocation = y;
}

uint8_t Bomb::returnYlocation()
{
    return this->lastYlocation;
}

uint8_t Bomb::returnExploded()
{
    return this->exploded;
}

void Bomb::setExploded(uint8_t exploded)
{
    this->exploded = exploded;
}

void Bomb::setTime(uint32_t time)
{
    this->lastKnownTime = time;
}

uint8_t Bomb::readyForNew(uint8_t x, uint8_t y)
{
    return (this->lastXlocation == 15 && this->lastYlocation == 15 && this->exploded == 1);
}