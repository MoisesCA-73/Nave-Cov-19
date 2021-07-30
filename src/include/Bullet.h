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

class Bullet
{
private:
    //Ammo
    sf::RectangleShape shape;
    sf::Texture bulletTexture;
    sf::Vector2f size;
    sf::Vector2f direction;

    //Bullets moving
    std::vector<sf::RectangleShape> bullets;
    //Bullet attributes
    int damage;
    float fireRate;
    float fireRateCount;
    float movementSpeed;

    //Private functions
    void initVariables();
    void initTexture();

public:
    //Constructors
    Bullet();
    //Destructor
    ~Bullet();

    //Accessors
    float getFireRate() const;

    //Mutators
    void setFireRate(float fireRate);

    void spawnBullet(sf::Vector2f coord);
    void shoot(sf::Vector2f coord);
    //void dealDamage(Virus enemy);
    //Functions
    void updateBullets();
    void updateInput(sf::Vector2f coord);
    void update(sf::Vector2f coord);
    void render(sf::RenderTarget *target);
};

#endif //BULLET_H