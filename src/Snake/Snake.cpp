#include "Snake.h"

Snake::Snake() {
	init();
}

void Snake::init() {
    n = 1; size = 4;
	m_coord = new CoordStr{10, 12};
    m_dir = Direction::RIGTH;
}

void Snake::savePosition() {
    body[n] = m_coord;
    body[0] = m_coord;
    n++;
    if (n == size) n = 1;
}

void Snake::moveTo() {
	switch (m_dir) {
		case Direction::UP:
			m_coord->y--;
		break;
		case Direction::DOWN:
			m_coord->y++;	
		break;
		case Direction::RIGTH:
			m_coord->x++;
		break;
		case Direction::LEFT:
			m_coord->x--;
		break;
	}
}

CoordStr Snake::at(int idx) { return *body[idx]; }
void Snake::set(int idx, CoordStr value) { body[idx] = &value; }
Direction Snake::dir() { return m_dir; }
void Snake::setDir(Direction dir) { m_dir = dir; }
CoordStr Snake::coord() { return *m_coord; }
void Snake::setCoord(CoordStr coord) { m_coord = &coord; }
