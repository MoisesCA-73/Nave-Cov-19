#ifndef INCREASE_HP_H
#define INCREASE_HP_H

#include "PowerUp.h"

class IncreaseHP : public PowerUp
{
private:
    virtual void initTexture() override;
    virtual void initShape() override;
public:
    IncreaseHP();
    virtual void makeChange(Player &player) override;

};
#endif  //DOUBLE_FIRE_RATE_H