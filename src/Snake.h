#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#ifndef _SNAKE_H_
#define _SNAKE_H_

class Snake{
    public:
        int cuerpo[1000][2];    // Cuerpo de la serpiente (coordenadas (x,y))
        int n;                  // Numero de casillas
        int tam;                // Tamanio de la serpietne
        int dir;                // Direccion de la serpiente
        int x, y;               // Coordenadas iniciales de la serpiente
        Snake();
        void initSnake();
        void guardar_posicion();    // Guardar posicion de la serpiente
        void moverse();

};

#endif