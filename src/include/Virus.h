#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
protected:
    int health; 
    float points;

    void initVariables();
    void initTexture();
    void initShape();

public:
    Virus();
    ~Virus();

    void destroy();
    void update();
    void updateInput();
    void render(sf::RenderTarget *target);
};

#endif //VIRUS_H