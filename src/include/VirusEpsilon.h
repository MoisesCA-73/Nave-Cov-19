#ifndef VIRUS_EPSILON_H
#define VIRUS_EPSILON_H

#include "Virus.h"

class VirusEpsilon : public Virus
{
private:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;
public:
    VirusEpsilon();
};

#endif  //VIRUS_EPSILON_H