/*
    Todo objeto que cae y que puede ser destruido
*/

#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Entidad
{
    protected:
        float health;
        float size;

    public:
        Entidad();
        void sizeEntidad();
        virtual ~Entidad();
};

#endif  //ENTIDAD_H