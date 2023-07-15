#include "Snake.h"

Snake::Snake() {
    n = 1; tam = 4;
    m_coord = {10, 12};
	dir = 3;
}

void Snake::initSnake() {
    n = 1; tam = 4;
	m_coord = {10, 12};
    dir = 3;
}

void Snake::guardar_posicion() {
    body[n] = m_coord;
    body[0] = m_coord;   // Posicion cabeza
    n++;
    if (n == tam) n = 1;
}

void Snake::moverse() {
	if (dir == 1) m_coord.y--;
    if (dir == 2) m_coord.y++;
    if (dir == 3) m_coord.x++;
    if (dir == 4) m_coord.x--;
}
