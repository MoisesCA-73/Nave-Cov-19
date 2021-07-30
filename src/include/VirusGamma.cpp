#include "VirusGamma.h"

void VirusGamma::initVariables()
{
    this->health = 100;
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
    this->shape.setSize(sf::Vector2f(50.f,50.f));

}

VirusGamma::VirusGamma()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
