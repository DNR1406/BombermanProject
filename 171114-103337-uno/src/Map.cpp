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

void Map::drawGrid()
{
    // Delete menu with overwriting the background
    lcd.fillRect(0, 0, 83, 240, RGB(160, 182, 219));
    lcd.fillRect(89, 4, 231, 231, RGB(30, 107, 7));
    lcd.fillRect(89, 0, 231, 4, RGB(255, 0, 0));
    lcd.fillRect(89, 235, 231, 5, RGB(255, 0, 0));

    lcd.drawText(5, 5, "Home", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    // Going thru the horizontal grids. We have 4 of them. Per 4 horizontal points
    // We draw 4 vertical squares the increment of the y1 and x1 are both 54 because
    // Of one square being 26 by 26 squares, so we need to skip 54
    int x1 = 131;
    for (uint8_t i = 0; i < 4; i++)
    {
        // Identifying the beginning y point
        int y1 = 46;
        for (uint8_t j = 0; j < 4; j++)
        {
            lcd.fillRect(x1, y1, 21, 21, RGB(0, 0, 0));
            lcd.drawRect(x1, y1, 21, 21, RGB(50, 50, 50));
            y1 += 42;
        }
        x1 += 42;
    }

    // Identifying the beginning x point
    x1 = 89;
    for (uint8_t i = 0; i < 11; i++)
    {
        int y = 4;
        for (uint8_t j = 0; j < 11; j++)
        {
            if (i == 0 || i == 10)
            {
                lcd.fillRect(x1, y, 21, 21, RGB(0, 0, 0));
                lcd.drawRect(x1, y, 21, 21, RGB(50, 50, 50));
                y += 21;
            }
            if (j == 0)
            {
                lcd.fillRect(x1, y, 21, 21, RGB(0, 0, 0));
                lcd.drawRect(x1, y, 21, 21, RGB(50, 50, 50));
            }
        }
        x1 += 21;
    }

    x1 = 110;
    for (uint8_t i = 0; i < 9; i++)
    {
        int y = 214;
        lcd.fillRect(x1, y, 21, 21, RGB(0, 0, 0));
        lcd.drawRect(x1, y, 21, 21, RGB(50, 50, 50));
        x1 += 21;
    }
}

void Map::drawBarrels(int x, int y)
{
    x = 21 * x + 110;
    y = 21 * y + 25;

    lcd.fillRect(x, y, 21, 21, RGB(255, 0, 0));
    // lcd.drawRect(x, y, 21, 21, RGB(20, 20, 20));
}

void Map::declareBarrels(uint8_t amount, barrel *barrelPositions)
{
    if (amount > 55)
    {
        amount = 55;
    }

    uint8_t barrelNumber = 0;
    for (uint8_t y = 0; y < 9; y++)
    {
        for (uint8_t x = 0; x < 9; x++)
        {
            if (!((x % 2 && y % 2) || (x + y <= 2) || (x + y >= 14)))
            {
                this->barrels[barrelNumber].x = x;
                this->barrels[barrelNumber].y = y;
                barrelNumber++;
            }
        }
    }
    srand(single_sample() % 3);

    // randomSeed(single_sample());
    for (uint8_t i = 0; i < amount; i++)
    {
        uint8_t rx = rand() % 9;
        uint8_t ry = rand() % 9;

        // These placements are already made on the grid,
        // they're solid, and can't declared to barrels
        while ((rx % 2 && ry % 2) || (rx + ry <= 2) || (rx + ry >= 14))
        {
            rx = rand() % 9;
            ry = rand() % 9;
        }

        for (uint8_t j = 0; j <= i; j++)
        {
            if (!this->barrels[j].barrel)
            {
                this->barrels[i] = {rx, ry, 1};
                drawBarrels(rx, ry);
            }
            else if (this->barrels[j].x == rx && this->barrels[j].y == ry)
            {
                i--;
            }
        }
    }
    for (uint8_t i = 0; i < amount; i++)
    {
        Serial.print(this->barrels[i].x);
        Serial.print("  ");
        Serial.println(this->barrels[i].y);
    }
    for (uint8_t i = 0; i < amount; i++)
    {
        barrelPositions[i] = this->barrels[i];
    }
}

void Map::getBarrels(uint8_t barrels[55])
{
    uint8_t barrelNumber = 0;
    for (uint8_t y = 0; y < 9; y++)
    {
        for (uint8_t x = 0; x < 9; x++)
        {
            if (!((x % 2 && y % 2) || (x + y <= 1) || (x + y >= 15)))
            {
                this->barrels[barrelNumber].x = x;
                this->barrels[barrelNumber].y = y;
                barrelNumber++;
            }
        }
    }

    for (uint8_t i = 0; i < 55; i++)
    {
        this->barrels[i].barrel = barrels[i];

        if (this->barrels[i].barrel)
        {
            drawBarrels(this->barrels[i].x, this->barrels[i].y);
        }
    }
}

void Map::init_adc_single_sample()
{
    ADMUX |= (1 << MUX0);                                // input analog A1 Arduino
    ADMUX |= (1 << REFS0);                               // 5 volt
    ADCSRA = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // clock/128
    ADCSRA |= (1 << ADEN);                               // ADC enable
}

// Single sample of pin A0
int Map::single_sample()
{
    uint16_t result;
    ADCSRA |= (1 << ADSC); // Start conversion
    while (ADCSRA & (1 << ADSC))
        ; // Wait
    result = ADC;
    return result;
}
