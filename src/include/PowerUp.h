#ifndef POWERUP_H
#define POWERUP_H

#include "Entidad.h"
#include "Player.h"

class PowerUp : public Entidad
{
protected:
    virtual void initVariables();
    virtual void initShape();
    virtual void initTexture();
public:
    
    //virtual ~PowerUp();
    sf::RectangleShape &getShape();
    const sf::Vector2f &getPos();
    float getMovementS();
    
    void update();
    void render(sf::RenderTarget* target);

    virtual void makeChange(Player& player);
};

#endif //POWERUP_H