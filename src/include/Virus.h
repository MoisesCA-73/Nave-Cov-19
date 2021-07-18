#ifndef VIRUS_H
#define VIRUS_H

#include "Entidad.h"

class Virus : protected Entidad
{
protected:

    float points;
    
public:
    Virus() : Entidad(){};
    ~Virus();

};

#endif  //VIRUS_H