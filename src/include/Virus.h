#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
protected:
    float points;
    void initVariables();
    void initTexture();
    void initShape();

public:
    Virus();
    ~Virus();
    void update();
    void updateInput();
    void render(sf::RenderTarget *target);
};

#endif //VIRUS_H