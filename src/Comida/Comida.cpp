#include "Comida.h"

Comida::Comida() {
    m_coord.x = (rand() % 73) + 4;
    m_coord.y = (rand() % 19) + 4; 
}

void Comida::initComida() {
    m_coord.x = (rand() % 73) + 4;
    m_coord.y = (rand() % 19) + 4;
}

bool Comida::colisionComida(CoordStr coord) {
    if (m_coord == coord) {
        initComida();
        return true;
    }
    return false;
}
