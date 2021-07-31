#include "Entidad.h"

//Init and private functions
void Entidad::initVariables()
{
    this->movementSpeed = 10.f;
}
void Entidad::initTexture()
{

}

//Constructor

Entidad::Entidad()
{
    this->initVariables();
    this->initShape();
    this->initTexture();
}

Entidad::~Entidad()
{
    
}

sf::RectangleShape &Entidad::getShape()
{
    return this->shape;
}

const sf::Vector2f &Entidad::getPos()
{
    return this->shape.getPosition();
}