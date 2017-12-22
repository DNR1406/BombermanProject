#include "include.h"
#include <time.h>
#include <stdlib.h>
#include <avr/io.h>
#include "wiring_private.h"
#include "pins_arduino.h"

// Map constructor
Map::Map()
{
}

void Map::drawPlayMap()
{
    // Delete menu with overwriting the background
    lcd.fillRect(89, 4, 231, 231, RGB(29, 79, 22));
    lcd.fillRect(0, 0, 320, 4, RGB(0, 0, 0));
    lcd.fillRect(0, 235, 320, 5, RGB(0, 0, 0));

    lcd.fillRect(0, 4, 89, 231, RGB(50, 50, 50));

    lcd.drawText(12, 10, "Home", RGB(255, 40, 40), RGB(50, 50, 50), 1);

    // Draws rectangle in playerbox
    lcd.drawText(12, 50, "Player 1 ", RGB(255, 40, 40), RGB(50, 50, 50), 1);
    lcd.fillRect(10, 64, 69, 50, RGB(15, 15, 15));
    lcd.fillCircle(44, 89, 12, RGB(14, 44, 135));

    // Draws lifes in Player one square
    lcd.drawText(12, 120, "LIVES: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);

    // Draws score in Player one square
    lcd.drawText(12, 130, "SCORE: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);

    // Draws rectangle in playerbox
    lcd.drawText(12, 148, "Player 2 ", RGB(255, 40, 40), RGB(50, 50, 50), 1);
    lcd.fillRect(10, 162, 69, 50, RGB(15, 15, 15));
    lcd.fillCircle(44, 187, 12, RGB(153, 12, 12));

    // Draws lifes in Player two square
    lcd.drawText(12, 220, "LIVES: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);

    //Drawing the inside walls
    int x = 131;
    uint8_t y = 46;
    for (uint8_t i = 0; i < 4; i++)
    {
        y = 46;
        for (uint8_t j = 0; j < 4; j++)
        {
            drawWalls(x, y);
            y += 42;
        }
        x += 42;
    }

    // Drawing the outside walls
    x = 89;
    for (uint8_t i = 0; i < 11; i++)
    {
        y = 4;
        for (uint8_t j = 0; j < 11; j++)
        {
            if (i == 0 || i == 10)
            {
                drawWalls(x, y);
                y += 21;
            }
            else if (j == 0)
            {
                drawWalls(x, y);
            }
            else if (j == 10)
            {
                drawWalls(x, 214);
            }
        }
        x += 21;
    }
}

// Daaw barrel
void Map::drawBarrels(int x, int y)
{
    x = 21 * x + 110;
    y = 21 * y + 25;

    lcd.fillRect(x + 1, y + 1, 20, 20, RGB(102, 38, 37));
    lcd.drawRect(x, y, 21, 21, RGB(20, 20, 20));
}

void Map::drawWalls(int x, uint8_t y)
{
    lcd.fillRect(x + 1, y + 1, 20, 20, RGB(0, 0, 0));
    lcd.drawRect(x, y, 21, 21, RGB(50, 50, 50));
}

void Map::deleteBarrels(uint16_t x, uint8_t y)
{
    this->barrels[x][y] = 0;
    x = 21 * x + 110;
    y = 21 * y + 25;
    lcd.fillRect(x, y, 21, 21, RGB(29, 79, 22));
}

void Map::declareBarrels(uint8_t amount)
{
    lcd.drawText(12, 30, "LEVEL: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    if (amount < 19)
    {
        lcd.drawText(62, 30, "1", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    }
    else if (amount < 37)
    {
        lcd.drawText(62, 30, "2", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    }
    else
    {
        lcd.drawText(62, 30, "3", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    }

    for (uint8_t x = 0; x < 9; x++)
    {
        for (uint8_t y = 0; y < 9; y++)
        {
            if ((x % 2 && y % 2) || (x == 7 && y == 7) || (x == 1 && y == 1))
            {
                this->barrels[x][y] = 2;
            }
            if (x + y <= 2 || x + y >= 14)
            {
                this->barrels[x][y] = 3;
            }
        }
    }

    this->barrels[1][1] = 2;
    this->barrels[7][7] = 2;

    init_adc_single_sample();
    srand(single_sample());

    for (uint8_t i = 0; i < amount; i++)
    {
        uint8_t x = rand() % 9;
        uint8_t y = rand() % 9;

        if (this->barrels[x][y])
        {
            i--;
        }
        else
        {
            this->barrels[x][y] = 1;
            drawBarrels(x, y);
        }
    }
}

void Map::placeBomb(uint16_t x, uint8_t y)
{
    // Draw bomb
    x = 21 * x + 120;
    y = 21 * y + 35;
    lcd.fillCircle(x, y, 7, RGB(0, 0, 0));
}

void Map::init_adc_single_sample()
{
    ADMUX |= (1 << MUX0);                                // input analog A1 Arduino
    ADMUX |= (1 << REFS0);                               // 5 volt
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // clock/128
    ADCSRA |= (1 << ADEN);                               // ADC enable
}

// Single sample of pin A0
uint16_t Map::single_sample()
{
    uint16_t result;
    ADCSRA |= (1 << ADSC); // Start conversion
    while (ADCSRA & (1 << ADSC))
        ; // Wait
    result = ADC;
    return result;
}