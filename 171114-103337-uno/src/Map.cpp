#include "include.h"

// Map constructor
Map::Map()
{
}

void Map::drawGrid()
{
    int drawingSize = 240;
    int subdivisions = 9;
    int subdivisionSize = drawingSize / subdivisions;
    lcd.fillScreen(RGB(255, 255,255));
    for (int i = 0; i <= subdivisions; i++)
    {
        int x = 85 + i * subdivisionSize;
        lcd.drawLine(x, 0, x, 240, RGB(0, 0, 0));
    }

    for (int i = 0; i <= subdivisions; i++)
    {
        int y = 2 + i * subdivisionSize;
        lcd.drawLine(85, y, 320, y, RGB(0, 0, 0));
    }
    lcd.drawLine(85, 0, 320, 0, RGB(0, 0, 0));
    lcd.drawLine(85, 1, 320, 1, RGB(0, 0, 0));
    lcd.drawLine(85, 239, 320, 239, RGB(0, 0, 0));
    lcd.drawLine(85, 238, 320, 238, RGB(0, 0, 0));
    lcd.drawLine(85, 237, 320, 237, RGB(0, 0, 0));

    lcd.fillRect(0,0,85,240, RGB(0,0,0));
};
