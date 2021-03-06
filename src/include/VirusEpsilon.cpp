#include "VirusEpsilon.h"

void VirusEpsilon::initVariables()
{
    this->movementSpeed = 1.5f;
    this->health = 100;
    this->points = 15;
}
void VirusEpsilon::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUSALPHA::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusEpsilon::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(90.f, 90.f));
}

VirusEpsilon::VirusEpsilon()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
int VirusEpsilon::getPoints()
{
    return this->points;
}
float VirusEpsilon::getMovementS()
{
    return this->movementSpeed;
}
