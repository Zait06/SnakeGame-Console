#include <conio.h>

#include "Game.h"
#include "../utils/screen.h"
#include "../utils/keyboard.h"

Game::Game() {
    velocidad = 200;
    score = 0;
    snake.initSnake();
    c.initComida();
}

void Game::borrarSerpiente() {
    gotoxy(snake.cuerpo[snake.n][0],snake.cuerpo[snake.n][1]);
    std::cout << " ";
}

void Game::dibujarSerpiente() {
    for (int i=1; i<snake.tam;i++) {
        gotoxy(snake.cuerpo[i][0],snake.cuerpo[i][1]);
        std::cout << (char) 111;
    }
    gotoxy(snake.cuerpo[0][0],snake.cuerpo[0][1]);
    std::cout << (char) 2;
}

void Game::pintarComida() {
    gotoxy(c.xc, c.yc);
    std::cout << (char) 4;
}

void Game::pintarMarco() {
    // Lineas horizontales
    for (int i=2; i<78; i++) {
        gotoxy(i,3);    std::cout << (char) 205;
        gotoxy(i,23);   std::cout << (char) 205;
    }

    // Lineas verticales
	for (int i=4; i<23; i++) {
        gotoxy(2,i);    std::cout << (char) 186;
        gotoxy(77,i);   std::cout << (char) 186;
    }

    // Esquinas
    gotoxy(2,3);    std::cout << (char) 201;
    gotoxy(2,23);   std::cout << (char) 200;
    gotoxy(77,3);   std::cout << (char) 187;
    gotoxy(77,23);  std::cout << (char) 188;
}

void Game::pintarScore() {
    gotoxy(3,1);
    printf("Score: %d",score);
}

bool Game::game_over() {
    if ( snake.y == 3 || snake.y == 23 || snake.x == 2 || snake.x == 77)
        return false;
    for (int j = snake.tam-1; j>0; j--) {
        if (snake.cuerpo[j][0] == snake.x && snake.cuerpo[j][1] == snake.y)
            return false;
    }
    return true;
}

void Game::teclear() {
    if (kbhit()) {
        m_key = getch();
		Keys key = static_cast<Keys>(m_key);
        switch(key) {
			case Keys::UP:
                if (snake.dir != 2) snake.dir = 1;
            break;
			case Keys::DOWN:
                if (snake.dir != 1) snake.dir = 2;
            break;
			case Keys::RIGTH:
                if (snake.dir != 4) snake.dir = 3;
            break;
			case Keys::LEFT:
                if (snake.dir != 3) snake.dir = 4;
            break;
			default: break;
        }
    }
}

void Game::cambiarVelocidad() {
    if (score % 20 == 0 && velocidad > 10) {
        velocidad -= 10;
    }
}

void Game::run() {

    DWORD threadID;
    HANDLE hiloComida;

    pintarMarco();
    pintarComida();

    while(m_key != static_cast<uint16_t>(Keys::ESC) && game_over()) {
        pintarScore();
        borrarSerpiente();
        snake.guardar_posicion();
        dibujarSerpiente();
        
        teclear();
        if (c.colisionComida(snake.x,snake.y)) {
            snake.tam++;
            score += 10;
            cambiarVelocidad();
            pintarComida();
            CloseHandle(hiloComida);
        }
        teclear();

        snake.moverse();
        Sleep(velocidad);
    }
}
