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

public:
    //Constructor
    Bullet();

    //Destructor
    ~Bullet();

};

#endif  //BULLET_H