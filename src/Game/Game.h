#ifndef _GAME_H_
#define _GAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "food.h"
#include "snake.h"
#include "bigchars.h"

class Game {
   public:
    Game();
    ~Game();
    void run();
    void tapKey();
    bool gameOver();
    void changeVelocity();
    void paintScore();
    
    static void paintFrame();
    static void paintPause(CoordStr init_coord);
    static void paintGameOver(CoordStr init_coord);

   private:
    int score;
    int velocity;
    bool m_isExit;
    bool m_isPause;
    Food* m_food;
    Snake* m_snake;
    uint16_t m_key;
    uint16_t m_prevKey;

    bool pause();
    void paintFood();
    void dropSnake();
    void paintSnake();
    bool foodInSnake();
};

#endif