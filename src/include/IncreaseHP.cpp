#include "IncreaseHP.h"

void IncreaseHP::initTexture()
{
    //texture
}

IncreaseHP::IncreaseHP()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
void IncreaseHP::makeChange(Player player)
{
    player.setHP(player.getHp() + 5);
}

