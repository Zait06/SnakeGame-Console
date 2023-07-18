#include <iostream>

struct CoordStr { 
	int x, y;
	bool operator==(const CoordStr &coordA) {
		return coordA.x == x && coordA.y == y;
	}
};
 
// Funcion que posiciona el cursor en la consola en coordenadas (x,y)
void gotoxy(CoordStr coord);

#ifdef _WIN32
    //code for Windows (32-bit and 64-bit, this part is common)
	#include <windows.h>
	#include <conio.h>
    #define CLEARSCREEN system("cls")
    #define CHECKKEY _kbhit()
	#define PAUSE system("pause>null")

#elif __linux__
    //code for linux
    #define CLEARSCREEN system("clear")
    #define CHECKKEY
	#define PAUSE system("read -rsp $'Press any key to continue...\n' -n 1")

#endif


