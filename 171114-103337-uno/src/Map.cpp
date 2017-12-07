#include "include.h"
#include <time.h>
#include <stdlib.h>
#include <Arduino.h>

// Map constructor
Map::Map()
{
}

void Map::drawGrid()
{
    // Delete menu with overwriting the background
    lcd.fillScreen(RGB(160, 182, 219));

    lcd.drawText(5, 5, "Home", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    // Two left over pixel lines on the top filled with black
    lcd.fillRect(0, 0, 320, 2, RGB(0, 0, 0));

    // Three left over pixel rows in the down side of the grid
    lcd.fillRect(0, 236, 320, 4, RGB(0, 0, 0));
    lcd.fillRect(83, 0, 3, 240, RGB(0, 0, 0));

    // The next block of code is about drawing the squares in the grid.
    // The squares should be static

    // Identifying the beginning x point
    int x1 = 112;

    // Going thru the horizontal grids. We have 4 of them. Per 4 horizontal points
    // We draw 4 vertical squares the increment of the y1 and x1 are both 54 because
    // Of one square being 26 by 26 squares, so we need to skip 54
    for (int i = 0; i < 4; i++)
    {
        // Identifying the beginning y point
        int y1 = 28;
        for (int j = 0; j < 4; j++)
        {
            lcd.fillRect(x1, y1, 26, 26, RGB(0, 0, 0));
            y1 += 52;
        }
        x1 += 52;
    }
}

void Map::drawBarrels(int x, int y)
{
    x = 26 * x + 86;
    y = 26 * y + 2;

    lcd.fillRect(x, y, 26, 26, RGB(255, 255, 0));
    // lcd.fillRect(x, y, 26, 26, RGB(rand() % 255, rand() % 255, rand() % 255));
}

void Map::declareBarrels(int amount, int *positions)
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

    amount += 2;
    srand(time(NULL));
    barrel barrels[amount];

    time_t t;

    srand((unsigned)time(&t));

    for (int i = 0; i < amount; i++)
    {
        int rx = rand() % 9;
        int ry = rand() % 9;

        // These placements are already made on the grid, they're solid, and can't be overwrited
        while ((rx % 2 && ry % 2) || (rx + ry <= 1) || (rx + ry >= 15))
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
