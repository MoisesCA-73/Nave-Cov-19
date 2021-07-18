/*
    First type of enemy

    Se le cambiara el nombre cuando decidan un nombre para los virus, si le ponemos los nombres de las variantes? xd
*/
#ifndef VIRUSA_H
#define VIRUSA_H

#include "Virus.h"

class VirusA : public Virus
{
private:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;
public:
    VirusA() : Virus(){};
};

#endif  //VIRUSA_H