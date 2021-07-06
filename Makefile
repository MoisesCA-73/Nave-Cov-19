all: compile link

compile:
	g++ -Isrc/include -c main.cpp src/include/Game.cpp src/include/Player.cpp

link:
	g++ Player.o -o Player Game.o -o Game main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system