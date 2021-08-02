/*
    Abstract Class that represents every object
    that falls down and can be destroyed
*/

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include <ctime>
class Entidad
{
protected:
    float movementSpeed;
    sf::Texture texture;
    sf::RectangleShape shape;
    //Protected functions
    virtual void initVariables() = 0;
    virtual void initTexture() = 0;
    virtual void initShape() = 0;

public:
    //virtual ~Entidad() = 0;
    virtual sf::RectangleShape &getShape() = 0;
    virtual const sf::Vector2f &getPos() = 0;
    virtual float getMovementS() = 0;
};
#endif //ENTIDAD_H