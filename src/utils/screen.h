#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __linux__
#include <stdio.h>
#endif

typedef struct CoordStr { 
	int x, y;
	bool operator==(const CoordStr &coordA) {
		return coordA.x == x && coordA.y == y;
	}
} CoordStr;

 
// Funcion que posiciona el cursor en la consola en coordenadas (x,y)
void gotoxy(CoordStr coord);

