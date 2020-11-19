#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Snake.h"
#include "Comida.h"

using namespace std;

// Numeros asociados a las flechas
#define UP      72
#define LEFT    75
#define RIGTH   77
#define DOWN    80
#define ESC     27
#define ENTER   13

#ifndef _GAME_H_
#define _GAME_H_

class Game{
    private:
        int velocidad;
        int score;
        Snake s;
        Comida c;
        void borrarSerpiente();
        void dibujarSerpiente();
        void pintarComida();
    public:
        Game();
        void pintarMarco();
        void pintarScore();
        bool game_over();
        void teclear();
        void cambiarVelocidad();
        void run();
};

#endif