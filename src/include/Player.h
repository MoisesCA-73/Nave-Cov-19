#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Player
{
private:
    sf::RectangleShape shape;

    float movementSpeed;

    sf::Texture playerTexture;

    //Funciones privadas
    void initVariables();
    void initTexture();
    void initShape();
public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    //Evalua las teclas presionadas
    void updateInput();

    //Actualiza el choque con los limites de la ventana
    void updateWindowBoundsCollision(const sf::RenderTarget* target);

    //Actualiza su posicion en la ventana
    void update(const sf::RenderTarget* target);

    //Se dibuja
    void render(sf::RenderTarget* target);

    
};

#endif  //PLAYER_H