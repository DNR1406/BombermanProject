#include "include.h"

// Map constructor
Map::Map()
{
}

void Map::drawGrid()
{
    // Delete menu with overwriting the background
    lcd.fillScreen(RGB(160, 182, 219));

    //     // Draw all vertical lines
    //     for (int i = 0; i <= 9; i++)
    //     {
    //         int x = 85 + i * 26;
    //         lcd.drawLine(x, 0, x, 240, RGB(0, 0, 0));
    //     }

    // // Draw all horizontal lines
    //     for (int i = 0; i <= 9; i++)
    //     {
    //         int y = 2 + i * 26;
    //         lcd.drawLine(85, y, 320, y, RGB(0, 0, 0));
    //     }

    // Two left over pixel lines on the top filled with black
    lcd.fillRect(85, 0, 235, 2, RGB(0, 0, 0));

    // Three left over pixel rows in the down side of the grid
    lcd.fillRect(85, 237, 235, 3, RGB(0, 0, 0));

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

void Map::drawBarrels(int x, int y){
    x = 26 * x + 85;
    y = 26 * y + 2;

    lcd.fillRect(x,y,26,26,RGB(222,184,135));


}

void Map::declareBarrels(){
    int rx = rand() % 8;
    int ry = rand() % 8;

    drawBarrels(rx,ry);
}
