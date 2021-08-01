#include "VirusDelta.h"

void VirusDelta::initVariables()
{
    this->movementSpeed = 2.f;
    this->health = 100;
    this->points = 10;
}
void VirusDelta::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUSALPHA::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusDelta::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(60.f, 60.f));
}

VirusDelta::VirusDelta()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
int VirusDelta::getPoints()
{
    return this->points;
}

float VirusDelta::getMovementS()
{
    return this->movementSpeed;
}
