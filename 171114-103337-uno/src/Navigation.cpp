#include "include.h"
#include <EEPROM.h>
#include <Arduino.h>
Options options = Options();
GameEngine gameEngine = GameEngine();

File myFile;

Navigation::Navigation()
{
}

void Navigation::screenInit()
{

    this->lcd.begin();
    // lcd.touchRead();
    // lcd.touchStartCal();
    // writeCalData();
    int val = 100;
    val = map(val, 0, 1023, 0, 100);
    if (val < 10)
    {
        val = 10;
    }

    lcd.led(val);
    // lcd.fillScreen(RGB(160, 182, 219));
}

void Navigation::calibrateScreen()
{
    lcd.touchRead();
    if (lcd.touchZ() || readCalData()) //calibration data in EEPROM?
    {
        writeCalData(); //write data to EEPROM
    }
    else
    {
        // lcd.touchStartCal();
        writeCalData();
    }
}

void Navigation::drawStartscreenButtons()
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

void Navigation::checkButtonPresses()
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
                gameEngine.startGame();
                checkHomeButton();
            }

            // Check if the button area from Option is touched
            else if ((lcd.touchX() > 95 && lcd.touchX() < 215) && (lcd.touchY() > 140 && lcd.touchY() < 170))
            {
                // Open Options and open checkHomeButton
                options.createOptionsButtons();
                checkOptionsButtons();
                // checkHomeButton();
                // showOptions();
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

void Navigation::checkOptionsButtons()
{
    int pressed = 1;
    while (pressed)
    {
        lcd.touchRead();
        if (lcd.touchZ())
        {
            // If this button is touched you'll be navigate back to the home screen.
            if ((lcd.touchX() > 0 && lcd.touchX() < 50) && (lcd.touchY() > 0 && lcd.touchY() < 50))
            {
                // Get out of the while loop
                pressed = 0;

                // Go back to the start menu
                drawStartscreenButtons();
            }
            // Check if the button area from Brightness is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 100 && lcd.touchY() < 130))
            {
                options.changeBrightness();
                options.createOptionsButtons();
            }
            // Check if the button area from Volume is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 140 && lcd.touchY() < 170))
            {
                lcd.fillScreen(RGB(160, 182, 219));
                lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                lcd.drawText(100, 20, "VOLUME", RGB(0, 0, 0), RGB(160, 182, 219), 2);
                // functie volume
                checkOptionsButton();
            }
            // Check if the button area from Reset Highscore is touched
            else if ((lcd.touchX() > 40 && lcd.touchX() < 250) && (lcd.touchY() > 180 && lcd.touchY() < 210))
            {
                lcd.fillScreen(RGB(160, 182, 219));
                lcd.drawText(10, 10, "OPTIONS", RGB(255, 0, 0), RGB(160, 182, 219), 1);
                lcd.drawText(90, 20, "HIGHSCORE", RGB(0, 0, 0), RGB(160, 182, 219), 2);
                // readHighscoreFile();
                

                checkOptionsButton();
            }
        }
    }
}

// Check if the home button (which is only in "Settings" and "Credits") is pressed
void Navigation::checkHomeButton()
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
void Navigation::checkOptionsButton()
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
                options.createOptionsButtons();

                // Get out of the while loop
                back = 0;
            }
        }
    }
}

// Printing the credits in credits menu
void Navigation::showCredits()
{
    lcd.fillScreen(RGB(160, 182, 219));
    lcd.drawText(100, 20, "CREDITS", RGB(0, 0, 0), RGB(160, 182, 219), 2);
    lcd.drawText(30, 60, "Arno van de Munt (Waarborger)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 100, "Antal van Ravensteijn (troll meister)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 140, "Delano Remy (Notaris)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(30, 180, "Matthijs Koudijs (Scrum Master)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
    lcd.drawText(10, 10, "Home", RGB(255, 0, 0), RGB(160, 182, 219), 1);

    // Check if the home button is pushed
    checkHomeButton();
}

void Navigation::writeCalData(void)
{
    // create variables
    uint16_t i, addr = 0;
    uint8_t *ptr;

    // Write calibration data to EEPROM
    EEPROM.write(addr++, 0xAA);

    ptr = (uint8_t *)&lcd.tp_matrix;
    for (i = 0; i < sizeof(CAL_MATRIX); i++)
    {
        EEPROM.write(addr++, *ptr++);
    }

    return;
}

uint8_t Navigation::readCalData()
{
    // Creates variabeles
    uint16_t i, addr = 0;
    uint8_t *ptr;
    uint8_t c;

    // Reads calibration data from EEPROM
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

void Navigation::readHighscoreFile()
{
    int x;
    String a = "speler: DEL 42069";

    //init SD-Card
    Serial.println("Init SD-Card...");
    x = lcd.drawText(5, 5, "Init SD-Card...", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    if (!SD.begin(4)) //cs-pin=4
    {
        Serial.println("failed");
        lcd.drawText(x, 5, "failed", RGB(0, 0, 0), RGB(255, 255, 255), 1);
        while (1)
            ;
    }

    //open file for writing
    Serial.println("Open File...");
    x = lcd.drawText(5, 5, "Open File...", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    myFile = SD.open("TEST.txt", FILE_WRITE);
    if (myFile)
    {
        Serial.println("Writing...");
        lcd.drawText(5, 5, "Writing...", RGB(0, 0, 0), RGB(255, 255, 255), 1);
        myFile.println(a);
        myFile.close();
    }
    else
    {
        Serial.println("error");
        lcd.drawText(x, 5, "error", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    }

    //open file for reading
    Serial.println("Open File...");
    x = lcd.drawText(5, 5, "Open File...", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    myFile = SD.open("TEST.txt");
    if (myFile)
    {
        Serial.println("Reading...");
        lcd.drawText(x, 5, "Reading...", RGB(0, 0, 0), RGB(255, 255, 255), 1);
        lcd.setCursor(0, 20);
        while (myFile.available())
        {
            uint8_t c;
            c = myFile.read();
            Serial.write(c);
            lcd.print((char)c);
        }
        myFile.close();
    }
    else
    {
        Serial.println("error");
        lcd.drawText(x, 5, "error", RGB(0, 0, 0), RGB(255, 255, 255), 1);
    }
}
