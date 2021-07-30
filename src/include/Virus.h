#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
protected:
    int health;
    float points;
    //Private Functions
    virtual void initVariables();
    virtual void initTexture();
    virtual void initShape();

public:
    ~Virus();

    void destroy();
    sf::RectangleShape &getShape();
    const sf::Vector2f &getPos();
};

#endif //VIRUS_H