#include "DoubleFireRate.h"

void DoubleFireRate::initTexture()
{
    if (!this->texture.loadFromFile("Textures/dfr.png"))
    {
        std::cout << "ERROR::DFR::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}

void DoubleFireRate::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

void DoubleFireRate::makeChange(Player& player)
{
    player.bullet.setFireRate(player.bullet.getFireRate()/2);
}

DoubleFireRate::DoubleFireRate()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}