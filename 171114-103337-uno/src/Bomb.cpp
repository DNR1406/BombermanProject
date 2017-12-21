#include "include.h"
#include "Globals.h"

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
uint8_t Bomb::checkDetonation()
{
    return ((this->lastKnownTime + 500) < counterTimer2);
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

void Bomb::printBomb()
{
    Serial.println("BOMB");
    Serial.print(this->lastXlocation);
    Serial.print(" ");
    Serial.println(this->lastYlocation);
    Serial.println(this->lastKnownTime);
    Serial.println();
}