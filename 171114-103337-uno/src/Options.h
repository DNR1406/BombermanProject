#include "include.h"
#include <MI0283QT9.h>


#ifndef Options_H
#define Options_H


class Options
{
  public:
    Options();
    void createOptionsButtons();
    void changeBrightness();
    void storeHighscore();
    void showHighscore();
    void readHighscoreFile();

  private:
  MI0283QT9 lcd;
  int val;
  
};

#endif