#include "include.h"
#include <time.h>

// Map constructor
Map::Map()
{
}

void Map::drawGrid()
{
    // Delete menu with overwriting the background
    lcd.fillScreen(RGB(160, 182, 219));

    // Two left over pixel lines on the top filled with black
    lcd.fillRect(85, 0, 235, 2, RGB(0, 0, 0));

    // Three left over pixel rows in the down side of the grid
    lcd.fillRect(85, 236, 235, 4, RGB(0, 0, 0));

    lcd.fillRect(0, 0, 85, 240, RGB(0, 0, 0));

    // The next block of code is about drawing the squares in the grid.
    // The squares should be static

    // Identifying the beginning x point
    int x1 = 111;

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
    x = 26 * x + 85;
    y = 26 * y + 2;

<<<<<<< HEAD
    lcd.fillRect(x, y, 26, 26, RGB(222, 0,0));
=======


    // lcd.fillRect(x, y, 26, 26, RGB(255, 0, 0));
    lcd.fillRect(x,y,26,26,RGB(rand() % 255,rand() % 255,rand() % 255));
>>>>>>> b3721ef2f19c043b85cdca324e5b3172b065c62c
}

void Map::declareBarrels(int amount)
{
    amount += 2;
    srand (time(NULL));
    barrel barrels[amount];

    for (int i = 0; i < amount; i++)
    {
        int rx = rand() % 9;
        int ry = rand() % 9;

        // These placements are already made on the grid, they're solid, and can't be overwrited
        while ((rx % 2 == 1 && ry % 2 == 1) || (rx + ry <= 1) || (rx + ry >= 15))
        {
            rx = rand() % 9;
            ry = rand() % 9;
        }

        for (int j = 0; j < i; j++)
        {
            if (barrels[j].x == rx && barrels[j].y == ry)
            {
                i--;
            }
            else
            {
                barrels[i] = {rx, ry};

                drawBarrels(rx, ry);
            }
        }
    }
}
