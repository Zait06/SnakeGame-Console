#include "game.h"
#include <thread>
#include "system_actions.h"

Game::Game() {
    velocity = 200;
    score = 0;

    m_snake = new Snake();
    m_food = new Food();
    color::change(color::WHITE);
}

Game::~Game() {
    free(m_snake);
    free(m_food);
}

void Game::dropSnake() {
    setOnXY(m_snake->at(m_snake->n), ' ');
}

void Game::paintSnake() {
    color::change(color::GREEN);
    for (int i = 1; i < m_snake->size; i++) {
        setOnXY(m_snake->at(i), (char)111);
    }
    setOnXY(m_snake->at(0), (char)2);
    color::change(color::WHITE);
    hideCursor();
}

bool Game::foodInSnake()
{
    for (int idx = 0; idx < m_snake->size; idx++) {
        if (m_food->coord() == m_snake->at(idx))
            return true;
    }
    return false;
}

void Game::paintFood() {
    color::change(color::YELLOW);
    setOnXY(m_food->coord(), (char)178);
    color::change(color::WHITE);
}

void Game::paintFrame() {
    // Horizontal lines
    for (int i = 2; i < 78; i++) {
        setOnXY({i, 3}, (char)205);
        setOnXY({i, 23}, (char)205);
    }

    // Vertical lines
    for (int i = 4; i < 23; i++) {
        setOnXY({2, i}, (char)186);
        setOnXY({77, i}, (char)186);
    }

    // Corners
    setOnXY({2, 3}, (char)201);
    setOnXY({2, 23}, (char)200);
    setOnXY({77, 3}, (char)187);
    setOnXY({77, 23}, (char)188);
}

void Game::paintPause(CoordStr init_coord) {
    char_p(init_coord);
    char_a({init_coord.x + 10, init_coord.y});
    char_u({init_coord.x + 20, init_coord.y});
    char_s({init_coord.x + 30, init_coord.y});
    char_e({init_coord.x + 40, init_coord.y});
}

void Game::paintGameOver(CoordStr init_coord) {
    char_g(init_coord);
    char_a({init_coord.x + 10, init_coord.y});
    char_m({init_coord.x + 20, init_coord.y});
    char_e({init_coord.x + 30, init_coord.y});
    
    CoordStr next_coord = {init_coord.x, init_coord.y + 7};
    char_o(next_coord);
    char_v({next_coord.x + 10, next_coord.y});
    char_e({next_coord.x + 20, next_coord.y});
    char_r({next_coord.x + 30, next_coord.y});
}

bool Game::pause() {
    CLEAN_SCREEN;
    Game::paintFrame();
    paintScore();
    Game::paintPause({15, 10});
    color::change(color::YELLOW);
    gotoxy({12, 17});
    printf("Press [E] to exit or press any other key to continue...");
    color::change(color::WHITE);

    int key = GET_KEY;
    if (((char)key) == 'e' || ((char)key) == 'E') {
        return false;
    }

    m_key = m_prevKey;
    CLEAN_SCREEN;
    Game::paintFrame();
    paintScore();
    paintFood();

    return true;
}

void Game::paintScore() {
    gotoxy({3, 1});
    printf("Score: %d", score);
    hideCursor();
}

bool Game::gameOver() {
    CoordStr snakeCoord = m_snake->coord();
    if (snakeCoord.y == 3 || snakeCoord.y == 23 || snakeCoord.x == 2 || snakeCoord.x == 77)
        return true;
    for (int j = m_snake->size - 1; j > 0; j--) {
        if (m_snake->at(j) == snakeCoord)
            return true;
    }
    return false;
}

void Game::tapKey() {
    if (CHECK_KEY) {
        m_prevKey = m_key;
        m_key = GET_KEY;
        Keys key = static_cast<Keys>(m_key);
        switch (key) {
            case Keys::UP:
                if (m_snake->dir() != Direction::DOWN)
                    m_snake->setDir(Direction::UP);
                break;
            case Keys::DOWN:
                if (m_snake->dir() != Direction::UP)
                    m_snake->setDir(Direction::DOWN);
                break;
            case Keys::RIGTH:
                if (m_snake->dir() != Direction::LEFT)
                    m_snake->setDir(Direction::RIGTH);
                break;
            case Keys::LEFT:
                if (m_snake->dir() != Direction::RIGTH)
                    m_snake->setDir(Direction::LEFT);
                break;
            default:
                break;
        }
    }
}

void Game::changeVelocity() {
    if (score % 20 == 0 && velocity > 10)
        velocity -= 10;
}

void playSound() {
#ifdef _WIN32
    PlaySound(TEXT("../assets/sounds/CoinPlay.wav"), NULL, SND_FILENAME | SND_ASYNC);
#endif
}

void Game::run() {
    Game::paintFrame();
    paintFood();

    while (!gameOver()) {
        if (m_key == static_cast<uint16_t>(Keys::ESC)) {
            if (!pause()) break;
        }
        paintScore();
        dropSnake();
        m_snake->savePosition();
        paintSnake();

        tapKey();
        if (m_food->impact(m_snake->coord())) {
            playSound();
            m_food->init();
            while (foodInSnake()) {
                m_food->init();
            }
            m_snake->size++;
            score += 10;
            changeVelocity();
            paintFood();
        }
        tapKey();

        m_snake->moveTo();
        std::this_thread::sleep_for(std::chrono::milliseconds(velocity));
    }
}