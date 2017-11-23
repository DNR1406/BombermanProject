#include "include.h"
#include "Arduino.h"
#include <avr/io.h>
#include <util/delay.h>

GameEngine homeScreen = GameEngine();
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
}

<<<<<<< HEAD
void Options::changeBrightness()
{
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);
=======
// Function for changing the brightness of the screen
void Options::changeBrightness()
{
    // Background and back to options button
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    int sensorWaarde;
>>>>>>> 01ff15f7d76a208e03f8871cfb0b53b962551273
    int counter = 1;
    DDRC = 0b11111110;
    while (counter)
    {
         if (lcd.touchZ())
        {
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                homeScreen.showOptions();
                homeScreen.checkOptionsButton();
                counter = 0;
            }
        }
        int val = analogRead(DDC0);
        val = map(val, 0, 1023, 0, 100);
        lcd.led(val);
        lcd.touchRead();
    }
}