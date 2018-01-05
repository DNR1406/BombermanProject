// Own includes
#include "Map.hpp"

// Map constructor
Map::Map()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->barrels[i][j] = 0;
        }
    }
}

void Map::drawPlayMap()
{
    // Draw green background as "grass"
    lcd.fillRect(89, 4, 231, 231, RGB(29, 79, 22));

    // Black line at top and black line at bottom black
    lcd.fillRect(0, 0, 320, 4, RGB(0, 0, 0));
    lcd.fillRect(0, 235, 320, 5, RGB(0, 0, 0));

    // Draw grey background at left side of screen
    lcd.fillRect(0, 4, 89, 231, RGB(50, 50, 50));

    // "Avatar"  of player 1
    lcd.fillRect(10, 64, 69, 50, RGB(15, 15, 15));
    lcd.fillCircle(44, 89, 12, RGB(14, 44, 135));

    // "Avatar"  of player 2
    lcd.fillRect(10, 162, 69, 50, RGB(15, 15, 15));
    lcd.fillCircle(44, 187, 12, RGB(153, 12, 12));

    // Draw all text
    lcd.drawText(12, 10, "Home", RGB(255, 40, 40), RGB(50, 50, 50), 1);
    lcd.drawText(12, 50, "Player 1 ", RGB(255, 40, 40), RGB(50, 50, 50), 1);
    lcd.drawText(12, 120, "LIVES: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    lcd.drawText(12, 130, "SCORE: ", RGB(0, 0, 0), RGB(50, 50, 50), 1);
    lcd.drawText(12, 148, "Player 2 ", RGB(255, 40, 40), RGB(50, 50, 50), 1);
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

uint8_t Map::explosion(uint8_t x, uint8_t y)
{
    uint8_t score = 0;
    // If there is a barrel on the right side of the Bomb
    if (this->barrels[x + 1][y] == 1)
    {
        if (x < 8)
        {

            deleteBarrels(x + 1, y);
            score += 4;
        }
    }

    // If there is a barrel on the 2nd right side of the Bomb
    if (this->barrels[x + 2][y] == 1 && this->barrels[x + 1][y] != 2)
    {
        if (x < 7)
        {
            deleteBarrels(x + 2, y);
            score += 4;
        }
    }

    // If there is a barrel on the left side of the Bomb
    if (this->barrels[x - 1][y] == 1)
    {
        if (x)
        {
            deleteBarrels(x - 1, y);
            score += 4;
        }
    }

    // If there is a barrel on the 2nd left side of the Bomb and there is no wall inbetween
    if (this->barrels[x - 2][y] == 1 && this->barrels[x - 1][y] != 2)
    {
        if (x > 1)
        {
            deleteBarrels(x - 2, y);
            score += 4;
        }
    }

    // If there is a barrel on the bottom side of the Bomb
    if (this->barrels[x][y + 1] == 1)
    {
        if (y < 8)
        {
            deleteBarrels(x, y + 1);
            score += 4;
        }
    }
    // If there is a barrel on the 2nd bottom side of the Bomb and there is no wall inbetween
    if (this->barrels[x][y + 2] == 1 && this->barrels[x][y + 1] != 2)
    {
        if (y < 7)
        {
            deleteBarrels(x, y + 2);
            score += 4;
        }
    }

    // If there is a barrel on the top side of the Bomb
    if (this->barrels[x][y - 1] == 1)
    {
        if (y)
        {
            deleteBarrels(x, y - 1);
            score += 4;
        }
    }

    // If there is a barrel on the 2nd top side of the Bomb and there is no wall inbetween
    if (this->barrels[x][y - 2] == 1 && this->barrels[x][y - 1] != 2)
    {
        if (y > 1)
        {
            deleteBarrels(x, y - 2);
            score += 4;
        }
    }
    return score;
}


void Map::declareBarrels(uint8_t amount, uint8_t seed) {
    // Check level and print it out on the screen
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

    // Make sure these squares are already taken, so no barrels can be placed there
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
                // 3 means that no barrels can be placed there, but the player can still walk on it
                this->barrels[x][y] = 3;
            }
        }
    }

    this->barrels[1][1] = 2;
    this->barrels[7][7] = 2;

    srand(seed);

    // Randomly generate an "amount" of barrels, draw them on the screen and put them in the array
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
uint8_t Map::single_sample()
{
    uint8_t result;
    ADCSRA |= (1 << ADSC); // Start conversion
    while (ADCSRA & (1 << ADSC))
        ; // Wait
    result = ADC;
    return result;
}
