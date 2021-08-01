#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
protected:
    int health;
    int points;
    //Private Functions
    virtual void initVariables();
    virtual void initTexture();
    virtual void initShape();

public:
    ~Virus();

    void destroy();
    //Accessors
    sf::RectangleShape &getShape();
    const sf::Vector2f &getPos();
    int getHealth() const;
    int getPoints() const;

    //Mutators
    void setHealth(int health);
    void setPoints(int points);
};

#endif //VIRUS_H