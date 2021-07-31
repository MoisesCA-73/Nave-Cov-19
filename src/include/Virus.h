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
    //Accessors
    sf::RectangleShape &getShape();
    const sf::Vector2f &getPos();
    int getHealth() const;
    float getPoints() const;

    //Mutators
    void setHealth(int health);
    void setPoints(float points);

};

#endif //VIRUS_H