#ifndef VIRUS_DELTA_H
#define VIRUS_DELTA_H

#include "Virus.h"

class VirusDelta : public Virus
{
private:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;

public:
    VirusDelta();
    int getPoints();
};

#endif //VIRUS_DELTA_H