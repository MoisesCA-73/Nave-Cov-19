#include "Bullet.h"

void Bullet::initVariables()
{
    this->movementSpeed = 10.f;
}

void Bullet::initTexture()
{
    ;
}

Bullet::Bullet()
{
    this->initVariables();
    this->initTexture();
}
//Intentemos crear funciones privadas y esas ejecutarlas en los constructores
//asi como esta en Player.cpp o Game.cpp 
Bullet::Bullet(sf::Texture& texture,float dir_x,float dir_y,float movement_speed)
{
    this->shape.setTexture(texture);
    this->direction.x=dir_x;
    this->direction.y=dir_y;
    this->movementSpeed=movement_speed;
}
Bullet::~Bullet()
{

}

//Funciones publicas
//Cuando dispara
void Bullet::update()
{
    
}