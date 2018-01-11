// Other includes
#include <MI0283QT9.h>

#ifndef NavigationScreen_H
#define NavigationScreen_H

class NavigationScreen
{
public:
  // Startup
  NavigationScreen();
  NavigationScreen(uint8_t antal);

  // Headers
  void drawHeader(String text);
  void deleteHeader(String text);

  // Back buttons
  void drawBackButton();
  void deleteBackButton();

  // Normal buttons
  void drawButton(String text, uint8_t number, uint8_t textY, uint8_t textX);
  void deleteButton(uint8_t number);

  // Credits
  void drawCredits();
  void deleteCredits();

  // Highscores
  void readHighscoreFromEEPROM();
  void deleteHighscoreButtons();
  // Brightness
  void drawBrightness();
  void deleteBrightness();
  void setBrightness(uint8_t val);

  // Check for presses
  uint8_t checkTouchscreen();

  // Caliberation
  void writeCalData();
  uint8_t readCalData();
  MI0283QT9 lcd;

private:
  // Startup
  void startScreen();
};

#endif