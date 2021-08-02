all: compile link

compile:
	g++ -Isrc/include -c Nave\ Cov-19.cpp src/include/Game.cpp src/include/Player.cpp src/include/Menu.cpp src/include/Bullet.cpp src/include/Virus.cpp src/include/Enemies.cpp src/include/VirusBeta.cpp src/include/VirusAlpha.cpp src/include/VirusGamma.cpp src/include/VirusDelta.cpp src/include/VirusEpsilon.cpp src/include/PauseMenu.cpp src/include/DeathMenu.cpp

link:
	g++ DeathMenu.o -o DeathMenu PauseMenu.o -o PauseMenu Enemies.o -o Enemies Virus.o -o Virus VirusBeta.o -o VirusBeta VirusAlpha.o -o VirusAlpha VirusGamma.o -o VirusGamma VirusDelta.o -o VirusDelta VirusEpsilon.o -o VirusEpsilon Bullet.o -o Bullet Player.o -o Player Game.o -o Game Menu.o -o Menu Nave\ Cov-19.o -o Nave\ Cov-19 -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
