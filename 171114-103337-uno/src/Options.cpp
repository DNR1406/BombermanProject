#include "include.h"
#include "Arduino.h"
#include <avr/io.h>
#include <util/delay.h>
#include <MI0283QT9.h>

GameEngine homeScreen = GameEngine();
Navigation nav = Navigation();
Options::Options()
{
}

// Show the buttons of the Options
void Options::createOptionsButtons()
{

    // Fill screen with background, title, and back button
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(100, 20, "OPTIONS", RGB(0, 0, 0), RGB(160, 182, 219), 2);
    lcd.drawText(10, 10, "HOME", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    // Draws Brightness button
    lcd.fillRoundRect(40, 100, 250, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(40, 100, 250, 30, 5, RGB(0, 0, 0));
    lcd.drawText(85, 108, "BRIGHTNESS", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws Volume button
    lcd.fillRoundRect(40, 140, 250, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(40, 140, 250, 30, 5, RGB(0, 0, 0));
    lcd.drawText(115, 147, "VOLUME", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    // Draws Reset highscore button
    lcd.fillRoundRect(40, 180, 250, 30, 5, RGB(0, 100, 100));
    lcd.drawRoundRect(40, 180, 250, 30, 5, RGB(0, 0, 0));
    lcd.drawText(45, 187, "RESET HIGHSCORE", RGB(255, 0, 0), RGB(0, 100, 100), 2);

    checkOptionsButtons();
}

// Going back to options menu, this is needed when in brightness or volume page
void Options::checkOptionsBackButton()
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
                createOptionsButtons();

                // Get out of the while loop
                back = 0;
            }
        }
    }
}

void Options::checkOptionsButtons()
{
    int loopBool = 1;
    while (loopBool)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // If this button is touched you'll be navigate back to the home screen.
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                // Get out of the while loop
                loopBool = 0;

                // Go back to the start menu
                nav.drawStartscreenButtons();
            }
            // Check if the button area from Brightness is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 100 && lcd.touchY() < 130))
            {
                // Get out of the while loop
                loopBool = 0;

                // Going to void changeBrightness() to go to the change brightness page
                changeBrightness();

                // Checking if the options back button is being touched
                createOptionsButtons();
            }
            // Check if the button area from Volume is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 140 && lcd.touchY() < 170))
            {
                // Get out of the while loop
                loopBool = 0;
                lcd.fillScreen(RGB(160, 182, 219));
                lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                lcd.drawText(100, 20, "VOLUME", RGB(0, 0, 0), RGB(160, 182, 219), 2);
                checkOptionsBackButton();
            }
            // Check if the button area from Reset Highscore is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 180 && lcd.touchY() < 210))
            {
                // Get out of the while loop
                loopBool = 0;

                // Draw Reset Highscore page
                lcd.fillScreen(RGB(160, 182, 219));
                lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                lcd.drawText(40, 20, "RESET HIGHSCORE", RGB(0, 0, 0), RGB(160, 182, 219), 2);

                // Checking if the options back button is being touched
                checkOptionsBackButton();
            }
        }
    }
}

// Function for changing the brightness of the screen
void Options::changeBrightness()
{
    // Background and back to options button
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(80, 20, "BRIGHTNESS", RGB(0, 0, 0), RGB(160, 182, 219), 2);

    lcd.drawText(20, 100, "Turn potentiometer knob to change the ", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(20, 110, "brightness of the screen.", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(20, 120, "After you're done, press the screen", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(20, 130, "to go back.", RGB(0, 0, 0), RGB(160, 182, 219), 1);

    int counter = 1;
    DDRC = 0b11111110;
    while (counter)
    {
        int val = analogRead(DDC0);
        val = map(val, 0, 1023, 0, 100);
        if (val < 10)
        {
            val = 10;
        }

        lcd.led(val);
        lcd.touchRead();
        if (lcd.touchZ())
        {
            counter = 0;
        }
    }
}