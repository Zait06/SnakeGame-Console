#include "Food.h"

Food::Food() {
    m_coord.x = (rand() % 73) + 4;
    m_coord.y = (rand() % 19) + 4; 
}

void Food::init() {
    m_coord.x = (rand() % 73) + 4;
    m_coord.y = (rand() % 19) + 4;
}

bool Food::impact(CoordStr coord) {
    if (m_coord == coord) {
        init();
        return true;
    }
    return false;
}
