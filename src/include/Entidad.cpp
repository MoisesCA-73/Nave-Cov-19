#include "Entidad.h"

//Init and private functions
void Entidad::initVariables()
{
    this->movementSpeed = 10.f;
}
void Entidad::initTexture()
{

}

//Constructor

Entidad::Entidad()
{
    this->initVariables();
    this->initShape();
    this->initTexture();
}

Entidad::~Entidad()
{
    
}