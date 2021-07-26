all: compile link

compile:
	g++ -Isrc/include -c Nave\ Cov-19.cpp src/include/Game.cpp src/include/Player.cpp src/include/Menu.cpp src/include/Bullet.cpp

link:
	g++ Bullet.o -o Bullet Player.o -o Player Game.o -o Game Menu.o -o Menu Nave\ Cov-19.o -o Nave\ Cov-19 -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system