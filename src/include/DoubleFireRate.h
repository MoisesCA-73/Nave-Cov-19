#ifndef DOUBLE_FIRE_RATE_H
#define DOUBLE_FIRE_RATE_H

#include "PowerUp.h"

class DoubleFireRate : public PowerUp
{
private:
    virtual void initTexture() override;
    virtual void initShape() override;
public:
    DoubleFireRate();
    virtual void makeChange(Player& player) override;

};
#endif  //DOUBLE_FIRE_RATE_H