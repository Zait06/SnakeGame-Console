run: Snake Comida Game main
main:
	g++ main.cpp Snake.o Comida.o Game.o -o main -lwinmm
Game:
	g++ src/Game/Game.cpp -c
Comida:
	g++ src/components/food/food.cpp -c
Snake:
	g++ src/components/snake/snake.cpp -c