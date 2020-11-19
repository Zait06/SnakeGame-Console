#include <windows.h>

// Funcion que posiciona el cursor en la consola en coordenadas (x,y)
void gotoxy(int x, int y){
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = x;
    dwPos.Y = y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
}