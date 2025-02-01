#ifndef _FOOD_H_
#define _FOOD_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "screen.h"

class Food {
   public:
    Food();

    CoordStr coord();  // Food coordinate
    void setCoord(CoordStr coord);

    void init();
    bool impact(CoordStr coord);

   private:
    CoordStr m_coord;
};

#endif
