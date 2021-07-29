#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Bullet.h"

class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;
    int hp;

    sf::Texture playerTexture;

    Bullet bullet;


    //Funciones privadas
    void initVariables();
    void initTexture();
    void initShape();
public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    //Accessors
    Bullet getBullet() const;
    const int& getHp() const;

    //Recibe daño
    void Danio(const int danio);

    //Evalua las teclas presionadas
    void updateInput();

    //Actualiza el choque con los limites de la ventana
    void updateWindowBoundsCollision(const sf::RenderTarget* target);

    void updateBullet();

    //Actualiza su posicion en la ventana
    void update(const sf::RenderTarget* target);

    //Se dibuja
    void render(sf::RenderTarget* target);

    
};

#endif  //PLAYER_H
