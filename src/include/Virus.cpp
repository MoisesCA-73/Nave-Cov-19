#include "Virus.h"

//Init and private functions

void Virus::initVariables()
{
    //this->movementSpeed = 5.f;
    this->health = 10.f;
    this->points = 1;
    //this->maxEntities = 5;
    //this->entitySpawnTimerMax = 20.f;
    //this->entitySpawnTimer = this->entitySpawnTimerMax;
}
void Virus::initTexture()
{
    /*if (!this->texture.loadFromFile("Textures/virus.png"))
    {
        std::cout << "ERROR::VIRUS::INITEXTURE::COULD NOT LOAD TEXTURE!" << std::endl;
    }*/
}
void Virus::initShape()
{
    this->shape.setTexture(&this->texture);
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setPosition(0, 0);
}

//Constructor and destructor
Virus::~Virus()
{
}
sf::RectangleShape &Virus::getShape()
{
    return this->shape;
}
//Accessor
const sf::Vector2f &Virus::getPos()
{
    return this->shape.getPosition();
}

int Virus::getHealth() const
{
    return this->health;
}
int Virus::getPoints() const
{
    return this->points;
}

void Virus::setHealth(int health)
{
    this->health = health;
}

void Virus::setPoints(int points)
{
    this->points = points;
}