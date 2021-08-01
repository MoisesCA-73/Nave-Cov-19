#ifndef VIRUS_BETA_H
#define VIRUS_BETA_H

#include "Virus.h"

class VirusBeta : public Virus
{
protected:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;

public:
    VirusBeta();
    int getPoints() const;
};

#endif //VIRUS_BETA_H