/*
    Class that acts as the bullets that the spaceship
    shoots, and deals damage to entities.
*/

#ifndef BULLET_H
#define BULLET_H

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Virus.h"

class Player;
class Enemies;

class Bullet
{
private:
    //Ammo
    sf::RectangleShape shape;
    sf::Texture bulletTexture;
    sf::Vector2f size;
    //direccion

    //Sonido
    sf::SoundBuffer buffer;
    sf::Sound sonido;

    //Bullets moving
    std::vector<sf::RectangleShape> bullets;

    //Bullet attributes
    int damage;
    float fireRate;
    float fireRateCount;
    float fireRateMax;
    float movementSpeed;

    float DFRtimer;
    bool isDFR;

    //Private functions
    void initVariables();
    void initTexture();
    void initSound();

    //Friend class
    friend class Player;
    friend class Enemies;

public:
    //Constructors
    Bullet();
    //Destructor
    ~Bullet();

    //Accessors
    float getFireRate() const;
    int getDamage() const;
    std::vector<sf::RectangleShape> getBullets() const;

    //Mutators
    void setFireRate(float fireRate);

    //Methods
    void spawnBullet(sf::Vector2f coord);
    void shoot(sf::Vector2f coord);
    void updateBullets();
    void updateInput(sf::Vector2f coord);
    void update(sf::Vector2f coord);
    void render(sf::RenderTarget *target);
};

#endif //BULLET_H
