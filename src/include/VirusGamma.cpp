#include "VirusGamma.h"

void VirusGamma::initVariables()
{
    this->movementSpeed = 1.5f;
    this->health = 100;
    this->points = 20;
}
void VirusGamma::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUSALPHA::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusGamma::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(110.f, 110.f));
}

VirusGamma::VirusGamma()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
int VirusGamma::getPoints()
{
    return this->points;
}
float VirusGamma::getMovementS()
{
    return this->movementSpeed;
}
