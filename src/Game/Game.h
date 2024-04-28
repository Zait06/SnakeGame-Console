#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "../Food/Food.h"
#include "../Snake/Snake.h"

class Game {
   public:
    Game();
    void run();
    void paintFrame();
    void paintScore();
    bool gameOver();
    void tapKey();
    void changeVelocity();

   private:
    int score;
    int velocity;
    Food* m_food;
    Snake* m_snake;
    uint16_t m_key;

    void dropSnake();
    void paintSnake();
    void paintFood();
};

#endif