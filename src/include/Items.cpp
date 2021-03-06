#include "Items.h"

void Items::initVariables()
{
    this->itemSpawnTimerMax = 900.f;
    this->itemSpawnTimer = this->itemSpawnTimerMax;
}
Items::Items()
{
    this->initVariables();
}
void Items::spawnItem(sf::RenderTarget *target)
{
    //Randomize powerup type
    int type = rand() % 2;

    switch (type)
    {
    case 0:
        this->item = std::unique_ptr<DoubleFireRate>(new DoubleFireRate());
        break;
    case 1:
        this->item = std::unique_ptr<IncreaseHP>(new IncreaseHP());
        break;
    default:
        this->item = std::unique_ptr<IncreaseHP>(new IncreaseHP());
    }
    this->item->getShape().setPosition(static_cast<float>(rand() % static_cast<int>(target->getSize().x - this->item->getShape().getSize().x)), -100.f);
    this->items.push_back(std::move(this->item));
}

void Items::update(sf::RenderTarget *target, Player &player)
{
    if (this->itemSpawnTimer >= this->itemSpawnTimerMax)
    {
        this->spawnItem(target);
        this->itemSpawnTimer = 0.f;
    }
    else
    {
        this->itemSpawnTimer += 1.f;
    }
    for (int i = 0; i < this->items.size(); i++)
    {
        this->items[i]->getShape().move(0.f, 5.f);
        if (this->items[i]->getPos().y > target->getSize().y)
        {
            this->items.erase(this->items.begin() + i);
            i--;
        }
    }
    for (int i = 0; i < this->items.size(); i++)
    {
        if (this->items[i]->getShape().getGlobalBounds().intersects(player.getShape().getGlobalBounds()))
        {
            this->items[i]->makeChange(player);
            this->items.erase(this->items.begin() + i);
            i--;
        }
    }
}

void Items::render(sf::RenderTarget *target)
{
    for (auto &e : this->items)
    {
        target->draw(e->getShape());
    }
}