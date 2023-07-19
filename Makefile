run: Snake Comida Game main
main:
	g++ main.cpp Snake.o Comida.o Game.o -o main -lwinmm
Game:
	g++ ../src/Game.cpp -c
Comida:
	g++ ../src/Comida.cpp -c
Snake:
	g++ ../src/Snake.cpp -c