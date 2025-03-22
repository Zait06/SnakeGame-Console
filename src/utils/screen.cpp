#include "screen.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void gotoxy(CoordStr coord) {
#ifdef _WIN32
    COORD dwPos;
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    dwPos.X = coord.x;
    dwPos.Y = coord.y;
    SetConsoleCursorPosition(hCon, dwPos);
#else
    printf("\033[%d;%dH", coord.y + 1, coord.x + 1);
#endif
}

void setOnXY(CoordStr coord, char value) {
    gotoxy(coord);
    printf("%c", value);
    // fflush(stdout);
    fflush(stdout);
}

void hideCursor() {
    #ifdef _WIN32
        HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hCon, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hCon, &cursorInfo);
    #else
        printf("\e[?25l");
    #endif
}

void color::change(int value) {
#ifdef _WIN32
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, value);
#else
    printf("\033[0;%dm", value);
#endif
}