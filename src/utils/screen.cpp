#include "screen.h"

void gotoxy(CoordStr coord) {
	
	#ifdef _WIN32
    HANDLE hCon;
    COORD dwPos;

    dwPos.X = coord.x;
    dwPos.Y = coord.y;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hCon,dwPos);
	#endif

	#ifdef __linux__
	printf("\033[%d;%dH", coord.y + 1, coord.x + 1);
	#endif

}

typedef struct CoordStr CoordStr;

