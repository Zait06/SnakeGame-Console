#ifndef _COMIDA_H_
#define _COMIDA_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../utils/screen.h"

class Comida{
    public:
        Comida();

		CoordStr m_coord;	// Food coordinate
        
		void initComida();
        bool colisionComida(CoordStr coord);
};

#endif
