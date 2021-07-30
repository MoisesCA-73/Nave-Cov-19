/*
    Class that acts as the enemies on screen and randomizes
    the virus variants
*/

#ifndef ENEMIES_H
#define ENEMIES_H

#include "Virus.h"
#include <vector>
class Enemies
{
private:
    //Enemies objects
    float movementSpeed;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    Virus enemy;
    std::vector<Virus> enemies;
    //Private functions
    void initVariables();

public:
    Enemies();
    void spawnEnemy(sf::RenderTarget *target);
    void update(sf::RenderTarget *target);
    void render(sf::RenderTarget *target);
};
#endif //ENEMIES_H
