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

#include "include.h"
//Constructor
Options options = Options();
GameEngine::GameEngine()
{
}

// Start the home screen
void GameEngine::gameInit()
{
    this->lcd.begin();
    lcd.fillScreen(RGB(160, 182, 219));
}

// start Scherm functie
void GameEngine::startGame()
{
}

// functie om speler toe te voegen
void GameEngine::addPlayer()
{
}

// functie om level te selecteren
void GameEngine::selectLevel()
{
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

// Start touch screen and declare a place for the data
void GameEngine::calibrateScreen()
{
    // lcd.touchRead();
    if (lcd.touchZ() || readCalData()) //calibration data in EEPROM?
    {
        writeCalData(); //write data to EEPROM
    }
}

void GameEngine::readFromSDCard(char *file)
{
    //init SD-Card and calibrate touchscreen
    if (SD.begin(4))
    {
        OpenBMPFile(file, 0, 0);
    }
    else
    {
        lcd.drawText(5, 5, "Mislukt", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    }
}

// Check which button is pressed on the home screen.
void GameEngine::checkButtonPresses()
{
    int pressed = 1;
    while (pressed)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // Check if the button area from Start is touched
            if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 100 && lcd.touchY() < 130))
            {
                // Game starten
            }

            // Check if the button area from Option is touched
            else if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 140 && lcd.touchY() < 170))
            {
                // Open Options and open checkHomeButton
                showOptions();
            }

            // Check if the button area from Credits is touched
            else if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 180 && lcd.touchY() < 210))
            {
                // Open credits and open checkHomeButton
                showCredits();
            }
        }
    }
}

// Check if the home button (which is only in "Settings" and "Credits") is pressed
void GameEngine::checkHomeButton()
{
    int back = 1;
    while (back)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // Check if area is touched for going back to home screen
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                // Draw start screen
                drawStartscreenButtons();

                // Get out of the while loop
                back = 0;
            }
        }
    }
}

// Going back to options menu, this is needed when in brightness or volume page
void GameEngine::checkOptionsButton()
{
    int back = 1;
    while (back)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // Check if area is touched for going back to options screen
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                // Show the options menu
                showOptions();

                // Get out of the while loop
                back = 0;
            }
        }
    }
}

// Printing the credits in credits menu
void GameEngine::showCredits()
{
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(100, 20, "CREDITS", RGB(0, 0, 0), RGB(160, 182, 219), 2);
    lcd.drawText(30, 60, "Arno van de Munt (Waarborger)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 100, "Antal van Ravensteijn (Presentator)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 140, "Delano Remy (Notaris)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 180, "Matthijs Koudijs (Scrum Master)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(10, 10, "Home", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    // Check if the home button is pushed
    checkHomeButton();
}

// Showing the options menu and checking if buttons are being pressed
void GameEngine::showOptions()
{
    // Fill screen with the buttons "Brightness, Volume, and Reset Highscore, options title, home back button and background"
    options.createOptionsButtons();

    int pressed = 1;
    while (pressed)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // If this button is touched you'll be navigate back to the home screen.
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                // Go back to the start menu
                drawStartscreenButtons();

                // Get out of the while loop
                pressed = 0;
            }
            // Check if the button area from Brightness is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 100 && lcd.touchY() < 130))
            {
                options.changeBrightness();
                checkOptionsButton();
            }
            // Check if the button area from Volume is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 140 && lcd.touchY() < 170))
            {
                lcd.fillScreen(RGB(0, 255, 0));
                lcd.drawText(10, 10, "VOLUME", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                // functie volume
                checkOptionsButton();
            }
            // Check if the button area from Reset Highscore is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 180 && lcd.touchY() < 210))
            {
                lcd.fillScreen(RGB(0, 0, 255));
                lcd.drawText(10, 10, "HIGHSCORE", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                checkOptionsButton();
            }
        }
    }
}

void GameEngine::drawStartscreenButtons()
{
    // Background set
    lcd.fillScreen(RGB(160, 182, 219));

    // Draws start button
    lcd.fillRoundRect(95, 100, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 100, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(117, 108, "START", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws options button
    lcd.fillRoundRect(95, 140, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 140, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(100, 147, "OPTIONS", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws credits button
    lcd.fillRoundRect(95, 180, 120, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(95, 180, 120, 30, 5, RGB(0, 0, 0));
    lcd.drawText(100, 187, "CREDITS", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Check if any buttons are pressed
    checkButtonPresses();
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
