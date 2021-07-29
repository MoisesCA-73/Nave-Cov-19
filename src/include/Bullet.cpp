#include "Bullet.h"

void Bullet::initVariables()
{
    this->movementSpeed = 20.f;
    this->shape.setTexture(&this->bulletTexture);
    this->size = sf::Vector2f(20.f,40.f);
    this->shape.setSize(this->size);
    this->fireRate = 10.f;
    this->fireRateCount = this->fireRate;
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
    
    this->shape.setPosition(coord.x + 12.5, coord.y);
    this->bullets.push_back(this->shape);
}

void Bullet::updateBullets()
{
    for (size_t i = 0; i < this->bullets.size(); i++)
    {

        this->bullets[i].move(0.f, -movementSpeed);

        if (this->bullets[i].getPosition().y < 0.f)
        {
            this->bullets.erase(this->bullets.begin() + i);
            i--;
        }
    }
}
void Bullet::updateInput(sf::Vector2f coord)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
    {
        if (this->fireRateCount >= this->fireRate)
        {
            this->shoot(coord);
            this->fireRateCount = 0.f;
        }
        else
        {
            this->fireRateCount += 1.0;
        }
    }
    else
    {
        //this->keyHeld = false;
    }
}

//Funciones publicas

//Cuando dispara
void Bullet::update(sf::Vector2f coord)
{
    this->updateInput(coord);
    this->updateBullets();
}

void Bullet::render(sf::RenderTarget* target)
{
    for (auto& e : bullets)
    {
        target->draw(e);
    }
}