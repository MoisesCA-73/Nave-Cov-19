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
    if (!this->texture.loadFromFile("Textures/nave.png"))
    {
        std::cout << "ERROR::PLAYER::INITEXTURE::Could not load texture" << std::endl;
    }
}
void Virus::initShape()
{
    this->shape.setTexture(&this->texture);
    //this->shape.
}
//Constructor and destructor

Virus::Virus() : Entidad()
{
}

Virus::~Virus()
{
}