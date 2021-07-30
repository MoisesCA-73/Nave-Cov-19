#include "VirusDelta.h"

void VirusDelta::initVariables()
{
    this->health = 100;
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
    this->shape.setSize(sf::Vector2f(20.f,20.f));

}

VirusDelta::VirusDelta()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
