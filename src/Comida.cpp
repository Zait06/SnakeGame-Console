#include "Comida.h"

Comida::Comida(){
    xc = (rand()%73)+4;
    yc = (rand()%19)+4; 
}

void Comida::initComida(){
    xc = (rand()%73)+4;
    yc = (rand()%19)+4; 
}

bool Comida::colisionComida(int x, int y){
    if(x == xc && y == yc){
        initComida();
        return true;
    }
    return false;
}