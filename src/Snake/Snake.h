#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../utils/screen.h"

class Snake{
    public:
        Snake();

        CoordStr body[1000];    // Cuerpo de la serpiente (coordenadas (x,y))
        int n;                  // Numero de casillas
        int tam;                // Tamanio de la serpietne
        int dir;                // Direccion de la serpiente
		CoordStr m_coord;

        void initSnake();
        void guardar_posicion();    // Guardar posicion de la serpiente
        void moverse();

};

#endif
