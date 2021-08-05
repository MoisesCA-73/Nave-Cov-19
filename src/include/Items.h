#ifndef ITEMS_H
#define ITEMS_H

#include "Player.h"
#include "DoubleFireRate.h"
#include "IncreaseHP.h"

#include <vector>
#include <ctime>

class Items
{
private:
    //Items objects
    float movementSpeed;
    float itemSpawnTimer;
    float itemSpawnTimerMax;

    std::unique_ptr<PowerUp> item;
    std::vector<std::unique_ptr<PowerUp>> items;
    
    //Private functions
    void initVariables();
    void initItems();

public:
    Items();
    void spawnItem(sf::RenderTarget *target);
    void update(sf::RenderTarget *target, Player &player);
    void render(sf::RenderTarget *target);
};
#endif //ITEMS_H