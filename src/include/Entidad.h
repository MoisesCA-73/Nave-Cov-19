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

class Entidad
{
protected:
    float movementSpeed;
    sf::Texture texture;
    sf::RectangleShape shape;

    //Protected functions
    virtual void initVariables()=0;
    virtual void initTexture()=0;
    virtual void initShape()=0;

public:

    Entidad();
    virtual ~Entidad();
};

#endif  //ENTIDAD_H