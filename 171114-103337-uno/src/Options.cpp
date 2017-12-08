#include "include.h"
#include <avr/io.h>
#include <EEPROM.h>
#include <util/delay.h>

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

    uint8_t counter = 1;
    init_adc_single_sample();
    while (counter)
    {
        int val = single_sample();
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

// Create single sample for A0 and enables ADC
void Options::init_adc_single_sample()
{
	ADMUX = 0;		// input analog A0 Arduino
	ADMUX |= (1<<REFS0);	// 5 volt
	ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0); // clock/128
	ADCSRA |= (1<<ADEN);	// ADC enable
}

// Single sample of pin A0
int Options::single_sample()
{
	uint16_t result;
	ADCSRA |= (1<<ADSC);		// Start conversion
	while(ADCSRA & (1<<ADSC)) ;	// Wait
	result = ADC;
	return result;
}

