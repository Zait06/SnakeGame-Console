#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef _COMIDA_H_
#define _COMIDA_H_

class Comida{
    public:
        int xc, yc;     // Coordenadas de la comida
        Comida();
        void initComida();
        bool colisionComida(int,int);
};

#endif