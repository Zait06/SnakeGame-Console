#include "Game.h"

Game::Game() {
    velocity = 200;
    score = 0;
    m_snake->init();
    m_food->init();
}

void Game::dropSnake() {
    gotoxy(m_snake->at(m_snake->n));
    printf(" ");
}

void Game::paintSnake() {
    for (int i = 1; i < m_snake->size ; i++) {
        gotoxy(m_snake->at(i));
        printf("%c", 111);
    }
    gotoxy(m_snake->at(0));
    printf("%c", 2);
}

void Game::paintFood() {
    gotoxy(m_food->coord());
    printf("%c", 4);
}

void Game::paintFrame() {
    // Horizontal lines
    for (int i=2; i<78; i++) {
        gotoxy({ i, 3 });	printf("%c", 205);
        gotoxy({ i, 23 });	printf("%c", 205);
    }

    // Vertical lines
	for (int i=4; i<23; i++) {
        gotoxy({ 2, i });	printf("%c", 186);
        gotoxy({ 77, i });	printf("%c", 186);
    }

    // Corners
    gotoxy({ 2, 3 });	printf("%c", 201);
    gotoxy({ 2, 23 });	printf("%c", 200);
    gotoxy({ 77, 3 });	printf("%c", 187);
    gotoxy({ 77, 23 });	printf("%c", 188);
}

void Game::paintScore() {
    gotoxy({ 3, 1 });
    printf("Score: %d", score);
}

bool Game::gameOver() {
	CoordStr snakeCoord = m_snake->coord();
    if ( snakeCoord.y == 3 || snakeCoord.y == 23 || snakeCoord.x == 2 || snakeCoord.x == 77)
        return false;
    for (int j = m_snake->size - 1; j > 0; j--) {
        if (m_snake->at(j) == snakeCoord)
            return false;
    }
    return true;
}

void Game::tapKey() {
	m_key = std::cin.get();
	Keys key = static_cast<Keys>(m_key);
    switch(key) {
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
		default: break;
    }
}

void Game::changeVelocity() {
    if (score % 20 == 0 && velocity > 10) {
        velocity -= 10;
    }
}

void Game::run() {
//    HANDLE hiloComida;

    paintFrame();
    paintFood();

    while(m_key != static_cast<uint16_t>(Keys::ESC) && gameOver()) {
        paintScore();
        dropSnake();
        m_snake->savePosition();
        paintSnake();
        
        tapKey();
        if (m_food->impact(m_snake->coord())) {
            m_snake->size++;
            score += 10;
            changeVelocity();
            paintFood();
//            CloseHandle(hiloComida);
        }
        tapKey();

        m_snake->moveTo();
		std::this_thread::sleep_for(std::chrono::milliseconds(velocity));
    }
}
