#include "IncreaseHP.h"

void IncreaseHP::initTexture()
{
     if (!this->texture.loadFromFile("Textures/hp.png"))
    {
        std::cout << "ERROR::IHP::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }
}

void IncreaseHP::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

IncreaseHP::IncreaseHP()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
void IncreaseHP::makeChange(Player &player)
{
    player.setHP(player.getHp() + 5);
}
