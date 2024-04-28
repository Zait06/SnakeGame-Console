#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../utils/keyboard.h"
#include "../utils/screen.h"

class Snake {
   public:
    Snake();
    int n;     // Cell number
    int size;  // Snake size

    Direction dir();
    void setDir(Direction dir);

    CoordStr at(int idx);
    void set(int idx, CoordStr value);

    CoordStr coord();
    void setCoord(CoordStr coord);

    void init();
    void moveTo();
    void savePosition();  // Save snake position

   private:
    CoordStr body[1000];  // Snake body
    Direction m_dir;      // Snake direction
    CoordStr* m_coord;    // Snake position (head)
};

#endif