#include <MI0283QT9.h>
#include <stdint.h>

#ifndef GameEngine_H
#define GameEngine_H

class GameEngine {
public:
    GameEngine();
    void startGame();
    void selectLevel();
    void incrementScore();
    void addPlayer();
    void readFromSDCard(char *file);
    void drawStartscreenButtons();
    void checkButtonPresses();
    void gameInit();
    void drawBackButton();
    int pressOptions();
    int pressCredits();
    uint8_t OpenBMPFile(char *file, int16_t x, int16_t y);
    uint8_t readCalData(void);
    void writeCalData(void);

   
  private:
    int score;
    MI0283QT9 lcd;
    
};


#endif