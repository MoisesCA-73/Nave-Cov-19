#include "Virus.h"

//Init and private functions
void Virus::initVariables()
{
    this->movementSpeed = 5.f;
    this->health = 10.f;
    this->points = 5.f;
    this->maxEntities = 5;
    this->entitySpawnTimerMax = 20.f;
    this->entitySpawnTimer = this->entitySpawnTimerMax;
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
//Functions
void Virus::spawn(sf::RenderTarget *target)
{
    /*
        @return void

        Spawns enemies and sets their types and colors and spaens them at positions randomly.
        -Sets a random type (dyff)
        -Sets a random position.
        -Sets a random color.
        -Adds enemy to vector
    */
    //Randomize position
    this->shape.setPosition(static_cast<float>(rand() % static_cast<int>(target->getSize().x - this->shape.getSize().x)), -100.f);
    //Spawn enemy
    this->entities.push_back(this->shape);
}
void Virus::update(sf::RenderTarget *target)
{
    /*
        @return void

        Updates the enemies spawn timer and spawn enemies
        when the total amount of enemies is smaller than the maximum;
        Moves the enemies downwards
        Removes the enemies at the edge of the screen.
    */
    if (this->entities.size() < this->maxEntities)
    {
        if (this->entitySpawnTimer >= this->entitySpawnTimerMax)
        {
            this->spawn(target);
            this->entitySpawnTimer = 0.f;
        }
        else
        {
            this->entitySpawnTimer += 1.f;
        }
    }
    for (int i = 0; i < this->entities.size(); i++)
    {
        //bool deleted{false};
        this->entities[i].move(0.f, 5.f);
        if (this->entities[i].getPosition().y > target->getSize().y)
        {
            this->entities.erase(this->entities.begin() + i);
        }
    }
}
void Virus::updateInput()
{
}
void Virus::render(sf::RenderTarget *target)
{
    for (auto &e : this->entities)
    {
        target->draw(e);
    }
}