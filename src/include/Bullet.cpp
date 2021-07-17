#include "Bullet.h"

Bullet::Bullet()
{

}
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