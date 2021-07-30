#include "Enemies.h"
void Enemies::initVariables()
{
    this->maxEnemies = 5.f;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
}
Enemies::Enemies()
{
    this->initVariables();
}
void Enemies::spawnEnemy(sf::RenderTarget *target)
{
    this->enemy.getShape().setPosition(static_cast<float>(rand() % static_cast<int>(target->getSize().x - this->enemy.getShape().getSize().x)), -100.f);
    this->enemies.push_back(this->enemy);
}

void Enemies::update(sf::RenderTarget *target)
{
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->spawnEnemy(target);
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }
    for (int i = 0; i < this->enemies.size(); i++)
    {
        this->enemies[i].getShape().move(0.f, 5.f);
        if (this->enemies[i].getPos().y > target->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
        }
    }
}

void Enemies::render(sf::RenderTarget *target)
{
    for (auto &e : this->enemies)
    {
        target->draw(e.getShape());
    }
}
