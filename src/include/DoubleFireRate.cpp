#include "DoubleFireRate.h"

void DoubleFireRate::initTexture()
{
    //texture
}
void DoubleFireRate::makeChange(Player player)
{
    player.getBullet().setFireRate(player.getBullet().getFireRate()/ 2);
}

DoubleFireRate::DoubleFireRate()
{
    this->initVariables();
    this->initTexture();
    this->initShape();
}
