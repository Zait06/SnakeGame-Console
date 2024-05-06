#include "screen.h"

void gotoxy(CoordStr coord) {

#ifdef _WIN32
    COORD dwPos;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos.X = coord.x;
    dwPos.Y = coord.y;
    SetConsoleCursorPosition(hCon, dwPos);
#endif

#ifdef __linux__
    printf("\033[%d;%dH", coord.y + 1, coord.x + 1);
#endif
}

void setOnXY(CoordStr coord, char value) {
    gotoxy(coord);
    printf("%c", value);
}

void hideCursor() {
#ifdef _WIN32
    COORD dwPos;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hCon, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hCon, &cursorInfo);
#endif
}

void color::change(int value) {
#ifdef _WIN32
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, value);
#else
    printf("\033[1;%dm", value);
#endif
}

typedef struct CoordStr CoordStr;