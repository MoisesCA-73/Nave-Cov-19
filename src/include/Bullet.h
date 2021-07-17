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
    sf::Sprite shape;
    sf::Vector2f size;
    sf::Vector2f direction;
    int damage;
    float fireRate;
    float movementSpeed;
public:
    //Constructor
    Bullet();

    Bullet(sf::Texture& texture,float dir_x,float dir_y,float movement_speed);
    //Destructor
    ~Bullet();
    //Functions
    void update();
    void render(sf::RenderTarget* target);
};

#endif  //BULLET_H