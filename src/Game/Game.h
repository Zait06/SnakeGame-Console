#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../Snake/Snake.h"
#include "../Comida/Comida.h"

class Game {
    private:
        uint16_t m_key;
		int velocidad;
        int score;
        Snake snake;
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
