#ifndef POWERUP_H
#define POWERUP_H

#include "Entidad.h"

class PowerUp : public Entidad
{
private:
    sf::RectangleShape shape;
    float movementSpeed;
    //sf::Texture1
    //sf::Texture2
    //...

    virtual void initVariables();
    virtual void initShape();
    virtual void initTexture();
public:
    PowerUp(float pos_x, float pos_y);
    virtual ~PowerUp();

    
    void update();
    void render(sf::RenderTarget* target);

};

#endif //POWERUP_H