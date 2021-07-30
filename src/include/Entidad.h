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
    float entitySpawnTimer;
    float entitySpawnTimerMax;
    int maxEntities;
    sf::Texture texture;
    sf::RectangleShape shape;
    std::vector<sf::RectangleShape> entities;
    //Protected functions
    virtual void initVariables() = 0;
    virtual void initTexture() = 0;
    virtual void initShape() = 0;

public:
    //virtual ~Entidad() = 0;
    virtual void spawn(sf::RenderTarget *target) = 0;
    virtual void update(sf::RenderTarget *target) = 0;
    virtual void updateInput() = 0;
    virtual void render(sf::RenderTarget *target) = 0;
};
#endif //ENTIDAD_H