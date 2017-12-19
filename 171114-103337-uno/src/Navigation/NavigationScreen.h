#include <MI0283QT9.h>

#ifndef NavigationScreen_H
#define NavigationScreen_H

class NavigationScreen
{
  public:
    // Startup
    NavigationScreen();

    // Headers
    void drawHeader(String text);
    void deleteHeader();

    // Back buttons
    void drawBackButton();
    void deleteBackButton();

    // Normal buttons
    void drawButton(String text, int number, int textY, int textX);
    void deleteButton(int number);

    // Credits
    void drawCredits();
    void deleteCredits();

    // Brightness
    void drawBrightness();
    void deleteBrightness();
    void setBrightness(int val);

    // Check for presses
    int checkTouchscreen();

    // Caliberation
    void writeCalData(void);
    uint8_t readCalData();

  private:
    // Startup
    void startScreen();

    // Variablen
    MI0283QT9 lcd;
};

#endif