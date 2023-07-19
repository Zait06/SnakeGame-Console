#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "Game/Game.h"
#include "system_actions/system_actions.h"

int main() {
	srand(time(NULL));
	CLEARSCREEN;
	Game game;
	game.run();
	PAUSE;
    return 0;
}

