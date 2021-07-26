#include "Bullet.h"

void Bullet::initVariables()
{
    this->movementSpeed = 20.f;
    this->keyHeld = false;
    this->shape.setTexture(&this->bulletTexture);
    this->size = sf::Vector2f(20.f,20.f);
    this->shape.setSize(this->size);
}

void Bullet::initTexture()
{
    if(!this->bulletTexture.loadFromFile("Textures/bullet-temporary.png"))
    {
        std::cout << "ERROR::BULLET::INITTEXTURE:: Failed to load texture!" << '\n' ;
    }
}

Bullet::Bullet()
{
    this->initTexture();
    this->initVariables();
}
//Intentemos crear funciones privadas y esas ejecutarlas en los constructores
//asi como esta en Player.cpp o Game.cpp 
Bullet::Bullet(sf::Texture& texture, float dir_x, float dir_y, float movement_speed)
{
    this->shape.setTexture(&texture);

    this->direction.x = dir_x;
    this->direction.y = dir_y;
    this->movementSpeed = movement_speed;
}
Bullet::~Bullet()
{

}

void Bullet::shoot(sf::Vector2f coord)
{
    this->shape.setPosition(coord.x, coord.y);

}

void Bullet::updateInput(sf::Vector2f coord)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        this->keyHeld = true;
        this->shoot(coord);

    }
}

//Funciones publicas

//Cuando dispara
void Bullet::update(sf::Vector2f coord)
{
    this->updateInput(coord);
    this->shape.move(0.f, -movementSpeed);
}

void Bullet::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}