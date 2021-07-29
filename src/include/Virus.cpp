#include "Virus.h"

//Init and private functions
void Virus::initVariables()
{
    this->movementSpeed = 5.f;
    this->health = 10.f;
    this->points = 5.f;
}
void Virus::initTexture()
{
    if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::Virus::INITEXTURE::Could not load texture" << std::endl;
    }
}
void Virus::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setPosition(0, 0);
}
//Constructor and destructor

Virus::Virus()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}

Virus::~Virus()
{
}
void Virus::update()
{
}
void Virus::updateInput()
{
}
void Virus::render(sf::RenderTarget *target)
{
    target->draw(this->shape);
}