#ifndef _FOOD_H_
#define _FOOD_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../utils/screen.h"

class Food{
    public:
        Food();

		CoordStr m_coord;	// Food coordinate
        
		void init();
        bool impact(CoordStr coord);
};

#endif
