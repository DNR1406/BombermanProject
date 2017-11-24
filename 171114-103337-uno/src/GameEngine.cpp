#include "GameEngine.h"
#include <EEPROM.h>
#include <SD.h>
#include <SPI.h>
#include <GraphicsLib.h>
#include <MI0283QT9.h>
#include <DS1307.h>
#include <wiring_private.h>
#include <stdint.h>
#include <Arduino.h>
#include <SD.h>
#include <TFT.h> // Arduino TFT library
#include <Wire.h>
#include <digitalWriteFast.h>
#include <BMPheader.h>
#include <stdint.h>

//Constructor
GameEngine::GameEngine()
{
}

void GameEngine::gameInit()
{
    this->lcd.begin();
}

// start Scherm functie
void GameEngine::startGame()
{
    selectLevel();

}

// functie om speler toe te voegen
void GameEngine::addPlayer()
{
}

// functie om level te selecteren
void GameEngine::selectLevel()
{
    lcd.fillScreen(RGB());
}

// functie om score van speler te incrementeren
void GameEngine::incrementScore()
{
}

uint8_t GameEngine::OpenBMPFile(char *file, int16_t x, int16_t y)
{
    File myFile;
    uint8_t buf[40]; //read buf (min. size = sizeof(BMP_DIPHeader))
    BMP_Header *bmp_hd;
    BMP_DIPHeader *bmp_dip;
    int16_t width, height, w, h;
    uint8_t pad;

    //open file
    myFile = SD.open(file);
    if (myFile)
    {
        //BMP Header
        myFile.read(&buf, sizeof(BMP_Header));
        bmp_hd = (BMP_Header *)&buf[0];
        if ((bmp_hd->magic[0] == 'B') && (bmp_hd->magic[1] == 'M') && (bmp_hd->offset == 54))
        {
            //BMP DIP-Header
            myFile.read(&buf, sizeof(BMP_DIPHeader));
            bmp_dip = (BMP_DIPHeader *)&buf[0];
            if ((bmp_dip->size == sizeof(BMP_DIPHeader)) && (bmp_dip->bitspp == 24) && (bmp_dip->compress == 0))
            {
                //BMP Data (1. pixel = bottom left)
                width = bmp_dip->width;
                height = bmp_dip->height;
                pad = width % 4; //padding (line is multiply of 4)
                if ((x + width) <= lcd.getWidth() && (y + height) <= lcd.getHeight())
                {
                    lcd.setArea(x, y, x + width - 1, y + height - 1);
                    for (h = (y + height - 1); h >= y; h--) //for every line
                    {
                        for (w = x; w < (x + width); w++) //for every pixel in line
                        {
                            myFile.read(&buf, 3);
                            lcd.drawPixel(w, h, RGB(buf[2], buf[1], buf[0]));
                        }
                        if (pad)
                        {
                            myFile.read(&buf, pad);
                        }
                    }
                }
                else
                {
                    lcd.drawText(x, y, "Pic out of screen!", RGB(0, 0, 0), RGB(255, 255, 255), 1);
                }
            }
        }

        myFile.close();
    }
}

void GameEngine::readFromSDCard(char *file)
{
    int x, i;

    //init Display
    // lcd.begin();

    //init SD-Card
    if (SD.begin(4))
    {
        lcd.fillScreen(RGB(0, 0, 0));
        lcd.touchRead();
        if (lcd.touchZ() || readCalData()) //calibration data in EEPROM?
        {
            lcd.touchStartCal(); //calibrate touchpanel
            writeCalData();      //write data to EEPROM
        }
        lcd.fillScreen(RGB(0, 0, 0));
        OpenBMPFile(file, 0, 0);
        drawStartscreenButtons();
    }
    else
    {
        lcd.drawText(5, 5, "Mislukt", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    }
}

void GameEngine::checkButtonPresses()
{
    int pressed = 1;
    while (pressed)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {

            // Credits openen
            if (showCredits())
            {
                OpenBMPFile("credits.bmp", 0, 0);
                pressed = 0;
                // Opties openen
            }
            else if (showOptions())
            {
                OpenBMPFile("options.bmp", 0, 0);
                pressed = 0;
            }
            else if (pressStart())
            {
                startGame();
            }
        }
    }
}
int GameEngine::pressCredits()
{
    if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 195 && lcd.touchY() < 225))
        return 1;
}

int GameEngine::pressOptions()
{
    if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 160 && lcd.touchY() < 190))
        return 1;
}

int GameEngine::pressStart()
{
    if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 125 && lcd.touchY() < 155)
        return 1;
}

void GameEngine::drawStartscreenButtons()
{
    // Draws start button
    lcd.fillRoundRect(95, 125, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 125, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(117, 133, "START", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws options button
    lcd.fillRoundRect(95, 160, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 160, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(100, 168, "OPTIONS", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws credits button
    lcd.fillRoundRect(95, 195, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 195, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(100, 203, "CREDITS", RGB(255, 0, 0), RGB(0, 100, 100), 2);
}

void GameEngine::drawBackButton()
{
    OpenBMPFile("backarrow.bmp", 0, 0);
}

void GameEngine::writeCalData(void)
{
    uint16_t i, addr = 0;
    uint8_t *ptr;

    EEPROM.write(addr++, 0xAA);

    ptr = (uint8_t *)&lcd.tp_matrix;
    for (i = 0; i < sizeof(CAL_MATRIX); i++)
    {
        EEPROM.write(addr++, *ptr++);
    }

    return;
}

uint8_t GameEngine::readCalData(void)
{
    uint16_t i, addr = 0;
    uint8_t *ptr;
    uint8_t c;

    c = EEPROM.read(addr++);
    if (c == 0xAA)
    {
        ptr = (uint8_t *)&lcd.tp_matrix;
        for (i = 0; i < sizeof(CAL_MATRIX); i++)
        {
            *ptr++ = EEPROM.read(addr++);
        }
        return 0;
    }

    return 1;
}
