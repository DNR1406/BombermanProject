#include "include.h"

#ifndef PlayerMovement_H
#define PlayerMovement_H

class PlayerMovement {
public:
    PlayerMovement(int x, int y);
    void left();
    void down();
    void up();
    void right();
    void clear();
    void draw();
   
 
    int x;
    int y;
    bool leftMove;
    bool rightMove;
    bool upMove;
    bool downMove;
    MI0283QT9 lcd;
};


#endif
