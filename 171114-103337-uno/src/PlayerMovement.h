#include "include.h"

#ifndef PlayerMovement_H
#define PlayerMovement_H

class PlayerMovement {
public:
    PlayerMovement(int xstartloc, int ystartloc, int r, int g, int b);
    void left();
    void down();
    void up();
    void right();
    void clear();
    void draw();
   
 
    int x;
    int y;
    int r;
    int g;
    int b;
    MI0283QT9 lcd;
};


#endif
