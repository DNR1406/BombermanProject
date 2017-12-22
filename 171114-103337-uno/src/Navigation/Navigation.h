#include "NavigationScreen.h"
#include "../GameEngine.h"
#include <MI0283QT9.h>

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

  // Highscores
  void drawHighscoreScreen();
  void startHighScoreScreen();
  void deleteHighScoreScreen();

  // PlayerSElect
  void drawPlayerSelectScreen();
  void startPlayerSelectScreen();
  void deletePlayerSelectScreen();

  // Other
  int getAnalogVal();
  void drawNotFinishedYet();
  void deleteNotFinishedYet();

  // Variablen
  GameEngine *gameEngine;
  NavigationScreen *screen;
  MI0283QT9 lcd;
};

#endif