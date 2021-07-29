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
class Entidad
{
protected:
    int health;
    float movementSpeed;
    sf::Texture texture;
    sf::RectangleShape shape;

    //Protected functions
    virtual void initVariables() = 0;
    virtual void initTexture() = 0;
    virtual void initShape() = 0;

public:
    Entidad();
    virtual ~Entidad() = 0;
    virtual void update() = 0;
    virtual void updateInput() = 0;
    virtual void render() = 0;
};
Entidad::Entidad()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
#endif //ENTIDAD_H