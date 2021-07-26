/*
    Class that acts as the bullets that the spaceship
    shoots, and deals damage to entities.
*/

#ifndef BULLET_H
#define BULLET_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Bullet
{
private:
    //Ammo
    sf::RectangleShape shape;
    sf::Texture bulletTexture;
    sf::Vector2f size;
    sf::Vector2f direction;
    //Bullet attributes
    int damage;
    float fireRate;
    float movementSpeed;

    bool keyHeld;

    //Private functions
    void initVariables();
    void initTexture();
public:
    //Constructors
    Bullet();
    Bullet(sf::Texture& texture,float dir_x,float dir_y,float movement_speed);
    //Destructor
    ~Bullet();

    void shoot(sf::Vector2f coord);
    //Functions
    void updateInput(sf::Vector2f coord);
    void update(sf::Vector2f coord);
    void render(sf::RenderTarget* target);
};

#endif  //BULLET_H