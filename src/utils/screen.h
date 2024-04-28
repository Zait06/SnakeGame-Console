#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

struct CoordStr {
    int x, y;
    bool operator==(const CoordStr &coordA) {
        return coordA.x == x && coordA.y == y;
    }
};

// Cursor position in coords
void gotoxy(CoordStr coord);

#endif  // _SCREEN_H_