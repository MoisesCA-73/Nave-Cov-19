#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
protected:
    int health;
    float points;
    //Private Functions
    void initVariables();
    void initTexture();
    void initShape();

public:
    Virus();
    ~Virus();

    void destroy();
    sf::RectangleShape &getShape();
    const sf::Vector2f &getPos();
};

#endif //VIRUS_H