#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : public Entidad
{
private:

    float points;
    
public:
    Virus() : Entidad(){};
    ~Virus();
};

#endif  //VIRUS_H