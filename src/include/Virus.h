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
    Virus() : Entidad(){};
    ~Virus();
    void update();
    void updateInput();
    void render();
};

#endif //VIRUS_H