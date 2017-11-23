#include "include.h"
#include "Arduino.h"
#include <avr/io.h>
#include <util/delay.h>

Options::Options() {

}

void Options::createOptionsButtons() {
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


void Options::changeBrightness() {
    int sensorWaarde;
    int counter = 1;
     DDRC = 0b11111110;

     while(counter) {
        sensorWaarde = analogRead(DDC0);
        counter = 0;
     }
}