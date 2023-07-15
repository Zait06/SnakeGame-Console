#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "utils/screen.h"
// #include "Game/Game.h"

int main() {

	CoordStr a = { 50, 20 };
	CoordStr b = { 50, 20 };

	std::cout << "Equals? " << (a == b) << std::endl;
	gotoxy(a);
	printf("gg");
    //srand(time(NULL));
   // Game game;
    //game.run();
//    system("pause>null");
    return 0;
}
