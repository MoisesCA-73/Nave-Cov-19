#ifndef VIRUS_GAMMA_H
#define VIRUS_GAMMA_H

#include "Virus.h"

class VirusGamma : public Virus
{
private:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;
public:
    VirusGamma();
};

#endif  //VIRUS_GAMMA_H