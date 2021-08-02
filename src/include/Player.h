#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Bullet.h"
class Enemies;
class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;
    int hp;
    int points;
    sf::Texture playerTexture;

    //Bullets that are shot
    Bullet bullet;

    //Funciones privadas
    void initVariables();
    void initTexture();
    void initShape();

    friend class Enemies;

public:
    Player(float x = 0.f, float y = 0.f);
    ~Player();

    //Accessors
    sf::RectangleShape getShape() const;
    Bullet &getBullet();
    int getPoints() const;
    int &getHp();

    //Setters
    void setPoints(int points);
    void setHP(int hp);

    //Recibe daño
    void Danio(const int danio);
    void RecibirDanio();

    //Evalua las teclas presionadas
    void updateInput();

    //Actualiza el choque con los limites de la ventana
    void updateWindowBoundsCollision(const sf::RenderTarget *target);

    void updateBullet();

    //Actualiza su posicion en la ventana
    void update(const sf::RenderTarget *target);

    //Se dibuja
    void render(sf::RenderTarget *target);
};

#endif //PLAYER_H
