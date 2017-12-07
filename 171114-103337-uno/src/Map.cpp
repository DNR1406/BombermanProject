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
    int immovableObject = 0;
    wall walls[immovableObject];
    int x1 = 131;
    for (int i = 0; i < 4; i++)
    {
        // Identifying the beginning y point
        int y1 = 46;
        for (int j = 0; j < 4; j++)
        {
            lcd.fillRect(x1, y1, 21, 21, RGB(0, 0, 0));
            lcd.drawRect(x1, y1, 21, 21, RGB(50, 50, 50));
            y1 += 42;
            this->walls[immovableObject].x = x1;
            this->walls[immovableObject].y = y1;
            // Serial.print(this->walls[immovableObject].x);
            // Serial.print(" ");
            // Serial.println(this->walls[immovableObject].y);
            immovableObject++;
        }
        x1 += 42;
    }

    // Identifying the beginning x point
    x1 = 89;
    for (int i = 0; i < 11; i++)
    {
        int y = 4;
        for (int j = 0; j < 11; j++)
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
    for (int i = 0; i < 9; i++)
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

    lcd.fillRect(x, y, 21, 21, RGB(115, 115, 115));
    // lcd.fillRect(x, y, 26, 26, RGB(rand() % 255, rand() % 255, rand() % 255));
}

void Map::declareBarrels(int amount, int *positions)
{
    init_adc_single_sample();
    positions[amount] = {}; // reset
    if (amount > 55)
    {
        amount = 55;
    }

    int barrelNumber = 0;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (!((x % 2 && y % 2) || (x + y <= 2) || (x + y >= 14)))
            {
                this->barrels[barrelNumber].x = x;
                this->barrels[barrelNumber].y = y;
                barrelNumber++;
            }
        }
    }

    
    barrel barrels[amount];

    randomSeed(single_sample());
    for (int i = 0; i < amount; i++)
    {
        int rx = rand() % 9;
        int ry = rand() % 9;

        // These placements are already made on the grid, they're solid, and can't be overwritten
        while ((rx % 2 && ry % 2) || (rx + ry <= 2) || (rx + ry >= 14))
        {
            rx = rand() % 9;
            ry = rand() % 9;
        }

        for (int j = 0; j < amount; j++)
        {
            if (this->barrels[j].x == rx && this->barrels[j].y == ry)
            {

                if (this->barrels[j].barrel) //Als je nog geen barrel hebt.
                {
                    i--;
                }
                else
                {
                    this->barrels[j].barrel = 1;
                    drawBarrels(rx, ry);
                }
            }
        }
    }

    for (int i = 0; i < amount; i++)
    {
        positions[i] = this->barrels[i].barrel;
    }
}

void Map::getBarrels(int barrels[59])
{
    int barrelNumber = 0;
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (!((x % 2 && y % 2) || (x + y <= 1) || (x + y >= 15)))
            {
                this->barrels[barrelNumber].x = x;
                this->barrels[barrelNumber].y = y;
                barrelNumber++;
            }
        }
    }

    for (int i = 0; i < 59; i++)
    {
        this->barrels[i].barrel = barrels[i];

        if (this->barrels[i].barrel)
        {
            drawBarrels(this->barrels[i].x, this->barrels[i].y);
        }
    }
}

void Map::getImmovableObjects(wall *walls)
{

    for (int i = 0; i < 16; i++)
    {
        walls[i] = this->walls[i];
    }
}

void Map::init_adc_single_sample()
{
	ADMUX |= (1<<MUX0);		// input analog A1 Arduino
	ADMUX |= (1<<REFS0);	// 5 volt
	ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // clock/128
	ADCSRA |= (1<<ADEN);	// ADC enable
}

// Single sample of pin A0
int Map::single_sample()
{
	uint16_t result;
	ADCSRA |= (1<<ADSC);		// Start conversion
	while(ADCSRA & (1<<ADSC)) ;	// Wait
	result = ADC;
	return result;
}


