#include "VirusEpsilon.h"

void VirusEpsilon::initVariables()
{
    this->health = 100;
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
    this->shape.setSize(sf::Vector2f(70.f,70.f));

}

VirusEpsilon::VirusEpsilon()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
