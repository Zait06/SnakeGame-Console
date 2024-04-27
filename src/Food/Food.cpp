#include "Food.h"

Food::Food() {
	init();
}

void Food::init() {
    m_coord.x = (rand() % 73) + 4;
    m_coord.y = (rand() % 19) + 4;
}

bool Food::impact(CoordStr coord) {
    if (m_coord == coord) {
        return true;
    }
    return false;
}

CoordStr Food::coord() { return m_coord; }
void Food::setCoord(CoordStr coord) { m_coord = coord; }
