#include <MI0283QT9.h>
#include <stdint.h>

#ifndef GameEngine_H
#define GameEngine_H

class GameEngine {
public:
    GameEngine();
    void startGame();
    void selectLevel();
    void setScore();
    void addPlayer();
   
  private:
    
    MI0283QT9 lcd;
};


#endif