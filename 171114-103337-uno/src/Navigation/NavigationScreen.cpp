// Own includes
#include "NavigationScreen.hpp"

// Other includes
#include <EEPROM.h> 

// Startup
NavigationScreen::NavigationScreen(uint8_t antal) {

}
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
 
void NavigationScreen::deleteHeader(String text)
{
  this->lcd.drawText(80, 20, text, RGB(160, 182, 219), RGB(160, 182, 219), 2);
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
void NavigationScreen::drawButton(String text, uint8_t number, uint8_t textX, uint8_t textY)
{
  lcd.fillRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(0, 100, 100));
  lcd.drawRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(0, 0, 0));
  lcd.drawText(textX, textY, text, RGB(255, 0, 0), RGB(0, 100, 100), 2);
}

void NavigationScreen::deleteButton(uint8_t number)
{
  lcd.fillRoundRect(40, (60 + (number * 40)), 250, 30, 5, RGB(160, 182, 219));
}

// Credits
void NavigationScreen::drawCredits()
{
  lcd.drawText(30, 60, "Arno van de Munt (Waarborger)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 100, "Antal van Ravensteijn (Waarborger)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 140, "Delano Remy (Notaris)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
  lcd.drawText(30, 180, "Matthijs Koudijs (Scrum Master)", RGB(0, 0, 0), RGB(160, 182, 219), 1);
}

void NavigationScreen::deleteCredits()
{
  lcd.fillRect(30,60,290,130,RGB(160,182,219));
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
  lcd.fillRect(20, 100, 300, 40, RGB(160, 182, 219));
}

void NavigationScreen::setBrightness(uint8_t val)
{
  // If the value of "val" will be less than 10, it'll be set back to 10
  // This way, the screen always has some light, and can never been turn off exidentally
  if (val < 10)
  {
    val = 10;
  }

  // The brightness can't be higher than 100, or a overflow will happen
  else if (val > 100)
  {
    val = 100;
  }
  lcd.led(val);
}

// Check for touchscreen presses
uint8_t NavigationScreen::checkTouchscreen()
{
  // Start read
  lcd.touchRead();

  // If any press
  if (lcd.touchZ())
  {
    // Read X and Y touch and put them in integers for easy accesable
    int x = lcd.touchX();
    int y = lcd.touchY();

    // check is the highest button is touched
    if ((x > 95 && x < 215) && (y > 100 && y < 130))
    {
      return 1;
    }

    // Check if the middle button is touched
    else if ((x > 95 && x < 215) && (y > 140 && y < 170))
    {
      return 2;
    }

    // Check if the lowest button is touched
    else if ((x > 95 && x < 215) && (y > 180 && y < 210))
    {
      return 3;
    }

    // Check if the "home"  or "back"  button on the top left side is touched
    else if ((x > 0 && x < 50) && (y > 0 && y < 50))
    {
      return 4;
    }
  }
  return 0;
}

// WriteCalData is meant for putting the Calibration data into the EEPROM.
// In theory this should only been done once.
void NavigationScreen::writeCalData()
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

// Read if there's Calibration data present in the EEPROM
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
  lcd.drawText(60, 50, "Player 1:", RGB(0, 0, 0), RGB(160, 182, 219), 2);

  // Reads out address 50, 51 and 52 from EEPROM. 
  // This is the place the highscores are saved.
  // They're already saved here on order. So no need to check again.

  lcd.drawInteger(205, 50, EEPROM.read(50) - 1, DEC, RGB(0, 0, 0), RGB(160, 182, 219), 2);
  lcd.drawInteger(205, 70, EEPROM.read(51) - 1, DEC, RGB(0, 0, 0), RGB(160, 182, 219), 2);
  lcd.drawInteger(205, 90, EEPROM.read(52) - 1, DEC, RGB(0, 0, 0), RGB(160, 182, 219), 2);
}

void NavigationScreen::deleteHighscoreButtons()
{
   lcd.fillRect(30,50,290,130,RGB(160,182,219));
}
