#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Game/Game.h"
#include "system_actions/system_actions.h"

int main() {
    srand(time(NULL));
    CLEARSCREEN;
    Game game;
    game.run();
#ifdef _WIN32
    PlaySound(TEXT("../sounds/GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
#endif
    PAUSE;
    return 0;
}
