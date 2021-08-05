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
class Game;
class Enemies
{
private:
    //Enemies objects
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    //Audio
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer1;
    sf::Sound sonido;
    sf::Sound sonido1;

    //Explosion sprite
    sf::RectangleShape explosion;
    std::vector<sf::RectangleShape> explosions;
    float explosionTimer;
    std::vector<float> explosionTimers;

    sf::Texture explosionTexture;

    //Enemies members
    std::unique_ptr<Virus> enemy;
    std::vector<std::unique_ptr<Virus>> enemies;
    //Private functions
    void initVariables();
    void initEnemies();
    void initExplosion();
    void initSound();
    //Friend class
    friend class Game;

public:
    Enemies();
    void spawnEnemy(sf::RenderTarget *target);
    void update(sf::RenderTarget *target, Player &player);
    void render(sf::RenderTarget *target);
};
#endif //ENEMIES_H
