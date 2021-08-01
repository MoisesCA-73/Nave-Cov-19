/*
    Class that acts as the enemies on screen and randomizes
    the virus variants
*/

#ifndef ENEMIES_H
#define ENEMIES_H
#include "Player.h"
#include "VirusAlpha.h"
#include "VirusBeta.h"
#include "VirusEpsilon.h"
#include "VirusGamma.h"
#include "VirusDelta.h"

#include <vector>
#include <ctime>

class Enemies
{
private:
    //Enemies objects
    float movementSpeed;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    //Sonido
    sf::SoundBuffer buffer;
    sf::Sound sonido;
    
    std::unique_ptr<Virus> enemy;
    std::vector<std::unique_ptr<Virus>> enemies;
    //Private functions
    void initVariables();
    void initEnemies();

public:
    Enemies();
    void spawnEnemy(sf::RenderTarget *target);
    void update(sf::RenderTarget *target, Player &player);
    void render(sf::RenderTarget *target);
};
#endif //ENEMIES_H
