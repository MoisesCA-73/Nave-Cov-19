#include "VirusAlpha.h"

void VirusAlpha::initVariables()
{
    this->health = 100;
}
void VirusAlpha::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUSALPHA::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}
void VirusAlpha::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(50.f,50.f));

}

VirusAlpha::VirusAlpha()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
