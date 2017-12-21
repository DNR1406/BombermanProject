#include "../include.h"

// Startup
NavigationScreen::NavigationScreen()
{
  // Start screen
  this->startScreen();
}

void NavigationScreen::startScreen()
{
  // Start screen
  this->lcd.begin();

  // Brightness
  lcd.led(100);

  // Fill screen light blue
  lcd.fillScreen(RGB(160, 182, 219));

  // Calibration
  lcd.touchRead();
  // Calibration data in EEPROM?
  // lcd.touchStartCal();
  if (lcd.touchZ() || readCalData())
  {
    // Write data to EEPROM
    writeCalData();
  }
  else
  {
    // lcd.touchStartCal();
    writeCalData();
  }
}

// Header
void NavigationScreen::drawHeader(String text)
{
  this->lcd.drawText(80, 20, text, RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

void NavigationScreen::deleteHeader()
{
  this->lcd.drawText(80, 20, "                ", RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

// Back button
void NavigationScreen::drawBackButton()
{
  lcd.drawText(10, 10, "BACK", RGB(255, 0, 0), RGB(160, 182, 219), 1);
}

void NavigationScreen::deleteBackButton()
{
  lcd.drawText(10, 10, "    ", RGB(255, 0, 0), RGB(160, 182, 219), 1);
}

// Draw normal button
void NavigationScreen::drawButton(String text, int number, int textX, int textY)
{
  lcd.fillRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(0, 100, 100));
  lcd.drawRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(0, 0, 0));
  lcd.drawText(textX, textY, text, RGB(255, 0, 0), RGB(0, 100, 100), 2);
}

void NavigationScreen::deleteButton(int number)
{
  lcd.fillRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(160, 182, 219));
}

// Credits
void NavigationScreen::drawCredits()
{
  lcd.drawText(30, 60, "Arno van de Munt (Waarborger)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 100, "Antal van Ravensteijn (troll meister)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 140, "Delano Remy (Notaris)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 180, "Matthijs Koudijs (Scrum Master)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
}

void NavigationScreen::deleteCredits()
{
  lcd.drawText(30, 60, "Arno van de Munt (Waarborger)", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(30, 100, "Antal van Ravensteijn (troll meister)", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(30, 140, "Delano Remy (Notaris)", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(30, 180, "Matthijs Koudijs (Scrum Master)", RGB(160, 182, 219), RGB(160, 182, 219), 1);
}

// Brightnes
void NavigationScreen::drawBrightness()
{
  lcd.drawText(20, 100, "Turn potentiometer knob to change the ", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(20, 110, "brightness of the screen.", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(20, 120, "After you're done, press the screen", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(20, 130, "to go back.", RGB(0, 0, 0), RGB(160, 182, 219), 1);
}

void NavigationScreen::deleteBrightness()
{
  lcd.drawText(20, 100, "Turn potentiometer knob to change the ", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(20, 110, "brightness of the screen.", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(20, 120, "After you're done, press the screen", RGB(160, 182, 219), RGB(160, 182, 219), 1);
  lcd.drawText(20, 130, "to go back.", RGB(160, 182, 219), RGB(160, 182, 219), 1);
}

void NavigationScreen::setBrightness(int val)
{
  if (val < 10)
  {
    val = 10;
  }
  lcd.led(val); 
  Serial.println(val);
}

// Check for touchscreen presses
int NavigationScreen::checkTouchscreen()
{
  // Start read
  lcd.touchRead();

  // If any press
  if (lcd.touchZ())
  {
    // Read X and Y touch
    int x = lcd.touchX();
    int y = lcd.touchY();

    // Check if the button area from Start is touched
    if ((x > 95 && x < 215) && (y > 100 && y < 130))
    {
      return 1;
    }

    // Check if the button area from Option is touched
    else if ((x > 95 && x < 215) && (y > 140 && y < 170))
    {
      return 2;
    }

    // Check if the button area from Credits is touched
    else if ((x > 95 && x < 215) && (y > 180 && y < 210))
    {
      return 3;
    }
    else if ((x > 0 && x < 50) && (y > 0 && y < 50))
    {
      return 4;
    }
  }
  return 0;
}

// Other
void NavigationScreen::writeCalData(void)
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

uint8_t NavigationScreen::readCalData()
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

void NavigationScreen::readHighscoreFromEEPROM()
{
  byte value = EEPROM.read(50);
  lcd.drawText(60, 50, "Player 1:", RGB(0, 0, 0), RGB(160, 182, 219), 2);
  lcd.drawInteger(205, 50, value - 1, DEC, RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

void NavigationScreen::deleteHighscoreButtons()
{
  byte value = EEPROM.read(50);
  lcd.drawText(60, 50, "Player 1:", RGB(160, 182, 219), RGB(160, 182, 219), 2);
  lcd.drawInteger(205, 50, value - 1, DEC, RGB(160, 182, 219), RGB(160, 182, 219), 2);
}
