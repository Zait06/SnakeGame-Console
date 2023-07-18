#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Game/Game.h"

int main() {
	srand(time(NULL));
	Game game;
	game.run();
	PAUSE;
    return 0;
}

