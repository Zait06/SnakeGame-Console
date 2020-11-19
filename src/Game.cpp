#include "Game.h"
#include "Draw.h"

using namespace std;

int tecla;
char soundComida[] = "..\\sounds\\CoinPlay.wav";

DWORD WINAPI playSoundComida(LPVOID lpParam){
    PlaySound((LPCTSTR)soundComida, NULL, SND_FILENAME | SND_ASYNC);
    return 0;
}

Game::Game(){
    velocidad = 200;
    score = 0;
    s.initSnake();
    c.initComida();
}

void Game::borrarSerpiente(){
    gotoxy(s.cuerpo[s.n][0],s.cuerpo[s.n][1]);
    cout<<" ";
}

void Game::dibujarSerpiente(){
    for(int i=1; i<s.tam;i++){
        gotoxy(s.cuerpo[i][0],s.cuerpo[i][1]);
        cout<<(char) 111;
    }
    gotoxy(s.cuerpo[0][0],s.cuerpo[0][1]);
    cout<<(char) 2;
}

void Game::pintarComida(){
    gotoxy(c.xc,c.yc);
    cout<<(char) 4;
}

void Game::pintarMarco(){
    // Lineas horizontales
    for(int i=2; i<78; i++){
        gotoxy(i,3);    cout<<(char) 205;
        gotoxy(i,23);   cout<<(char) 205;
    }

    // Lineas verticales
    for(int i=4; i<23; i++){
        gotoxy(2,i);    cout<<(char) 186;
        gotoxy(77,i);   cout<<(char) 186;
    }

    // Esquinas
    gotoxy(2,3);    cout<<(char) 201;
    gotoxy(2,23);   cout<<(char) 200;
    gotoxy(77,3);   cout<<(char) 187;
    gotoxy(77,23);  cout<<(char) 188;
}

void Game::pintarScore(){
    gotoxy(3,1);
    printf("Score: %d",score);
}

bool Game::game_over(){
    if( s.y == 3 || s.y == 23 || s.x == 2 || s.x == 77)
        return false;
    for(int j = s.tam-1; j>0; j--){
        if(s.cuerpo[j][0] == s.x && s.cuerpo[j][1] == s.y)
            return false;
    }
    return true;
}

void Game::teclear(){
    if(kbhit()){
        tecla = getch();
        switch(tecla){
            case UP:
                if(s.dir != 2) s.dir = 1;
            break;
            case DOWN:
                if(s.dir != 1) s.dir = 2;
            break;
            case RIGTH:
                if(s.dir != 4) s.dir = 3;
            break;
            case LEFT:
                if(s.dir != 3) s.dir = 4;
            break;
        }
    }
}

void Game::cambiarVelocidad(){
    if(score%20 == 0 && velocidad>10){
        velocidad -= 10;
    }
}

void Game::run(){

    DWORD threadID;
    HANDLE hiloComida;

    pintarMarco();
    pintarComida();

    while(tecla != ESC && game_over()){
        pintarScore();
        borrarSerpiente();
        s.guardar_posicion();
        dibujarSerpiente();
        
        teclear();
        if(c.colisionComida(s.x,s.y)){
            hiloComida = CreateThread(NULL,0,playSoundComida,NULL,0,&threadID);
            s.tam++;
            score += 10;
            cambiarVelocidad();
            pintarComida();
            CloseHandle(hiloComida);
        }
        teclear();

        s.moverse();
        Sleep(velocidad);
    }
}