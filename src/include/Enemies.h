/*
    Class that acts as the enemies on screen and randomizes
    the virus variants
*/

#ifndef ENEMIES_H
#define ENEMIES_H

#include "Virus.h"
#include <vector>
class Enemies
{
private:
    //Enemies objects
    Virus enemy;
    std::vector<Virus> enemies;

public:
    Enemies::Enemies();
    void spawnEnemy();


};
#endif  //ENEMIES_H
