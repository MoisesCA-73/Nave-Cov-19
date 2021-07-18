all: compile link

compile:
	g++ -Isrc/include -c Nave\ Cov-19.cpp src/include/Game.cpp src/include/Player.cpp

link:
	g++ Player.o -o Player Game.o -o Game Nave\ Cov-19.o -o Nave\ Cov-19 -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system