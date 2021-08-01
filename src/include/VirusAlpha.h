/*
    First type of enemy

    Se le cambiara el nombre cuando decidan un nombre para los virus, si le ponemos los nombres de las variantes? xd
    - ah claro jsjs c:
*/
#ifndef VIRUS_ALPHA_H
#define VIRUS_ALPHA_H

#include "Virus.h"

class VirusAlpha : public Virus
{
private:
    void initVariables() override;
    void initTexture() override;
    void initShape() override;

public:
    VirusAlpha();
    int getPoints() const;
    float getMovementS();
};

#endif //VIRUS_ALPHA_H