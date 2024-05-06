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
void setOnXY(CoordStr coord, char value);
void hideCursor();

namespace color {

#ifdef _WIN32
const int GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const int WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
#else
const int GREEN = 32;
const int YELLOW = 33;
const int WHITE = 37;
#endif

    void change(int value);

}

#endif  // _SCREEN_H_