#include "DoubleFireRate.h"

void DoubleFireRate::initTexture()
{
    //texture
}
void DoubleFireRate::makeChange(Player player)
{
    player.getBullet().setFireRate(player.getBullet().getFireRate()/ 2);
}
