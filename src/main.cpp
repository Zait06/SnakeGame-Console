#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "game.h"
#include "system_actions.h"

int main() {
    srand(time(NULL));
    CLEAN_SCREEN;
    Game game;
    game.run();
	CLEAN_SCREEN;
    Game::paintGameOver({20, 7});
	Game::paintFrame();
	printf("\n");
#ifdef _WIN32
    PlaySound(TEXT("../assets/sounds/GameOver.wav"), NULL, SND_FILENAME);
#endif
    return 0;
}
