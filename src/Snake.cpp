#include "Snake.h"

Snake::Snake(){
    n = 1; tam = 4;
    x = 10; y = 12;
    dir = 3;
}

void Snake::initSnake(){
    n = 1; tam = 4;
    x = 10; y = 12;
    dir = 3;
}

void Snake::guardar_posicion(){
    cuerpo[n][0] = x;
    cuerpo[n][1] = y;
    cuerpo[0][0] = x;   // Posicion cabeza
    cuerpo[0][1] = y;
    n++;
    if(n == tam) n = 1;
}

void Snake::moverse(){
    if(dir == 1) y--;
    if(dir == 2) y++;
    if(dir == 3) x++;
    if(dir == 4) x--;
}