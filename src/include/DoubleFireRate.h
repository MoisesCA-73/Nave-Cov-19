#ifndef DOUBLE_FIRE_RATE_H
#define DOUBLE_FIRE_RATE_H

#include "PowerUp.h"

class DoubleFireRate : public PowerUp
{
private:
    virtual void initTexture() override;
public:
    virtual void makeChange(Player player) override;

};
#endif  //DOUBLE_FIRE_RATE_H