#include "NavigationScreen.h"
#include "../GameEngine.h"

#ifndef Navigation_H
#define Navigation_H

class GameEngine;
class NavigationScreen;

class Navigation
{
public:
  // Start
  Navigation();
  void startStartScreen();

private:
  // Start
  void drawStartScreen();
  void deleteStartScreen();

  // Options
  void drawOptionsScreen();
  void deleteOptionsScreen();
  void startOptionsScreen();

  // Credits
  void drawCreditsScreen();
  void deleteCreditsScreen();
  void startCreditScreen();

  // Birhtness
  void drawBrightnessScreen();
  void deleteBrightnessScreen();
  void startBrightnessScreen();

  // Levelscreen
  void drawLevelScreen();
  void deleteLevelScreen();
  void startLevelScreen();

  // Other
  int getAnalogVal();
  void drawNotFinishedYet();
  void deleteNotFinishedYet();

  // Variablen
  GameEngine *gameEngine;
  NavigationScreen *screen;
};

#endif