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

    virtual void initVariables() override;
};

#endif  //VIRUS_H