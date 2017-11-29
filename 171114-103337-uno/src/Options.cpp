#include "include.h"
#include "Arduino.h"
#include <stdint.h>
#include <SD.h>
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
    lcd.drawText(90, 187, "HIGHSCORE", RGB(255, 0, 0), RGB(0, 100, 100), 2);
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

    int sensorWaarde;
    int counter = 1;
    DDRC = 0b11111110;
    while (counter)
    {
        // Reads val from Potentiometer pin
        int val = analogRead(DDC0);
        // Maps value from 0 and 1023 to 0 and 100
        val = map(val, 0, 1023, 0, 100);
        // Value can't get any lower then 10 otherwise it's dark
        if (val < 10)
        {
            val = 10;
        }
        // writes value to display
        lcd.led(val);
        lcd.touchRead();
        // if screen is pressed return to options screen
        if (lcd.touchZ())
        {
            counter = 0;
        }
    }
}




