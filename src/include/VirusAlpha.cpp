#include "VirusAlpha.h"

void VirusAlpha::initVariables()
{
    this->movementSpeed = 3.f;
    this->health = 100;
    this->points = 1;
}
void VirusAlpha::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus2.png"))
    {
        std::cout << "ERROR::VIRUSALPHA::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusAlpha::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(40.f, 40.f));
}

VirusAlpha::VirusAlpha()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
int VirusAlpha::getPoints() const
{
    return this->points;
}
float VirusAlpha::getMovementS()
{
    return this->movementSpeed;
}
