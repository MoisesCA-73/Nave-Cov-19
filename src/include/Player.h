#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class Player{
    private:
        sf::Sprite sprite;
        sf::Texture playerTexture;

        float movementSpeed;

        float attackCooldown;
        float attackCooldownMax;

        int hp;
        int hpMax;

        //Funciones privadas
        void initVariables();
        void initTexture();
        void initSprite();
    public:
        Player();
        virtual ~Player();

        //Accesor
        const sf::Vector2f& getPos() const;
        const sf::FloatRect getBounds() const;
        const int& getHp() const;
        const int& getHpMax() const;

        //Modificadores
        void setPosition(const sf::Vector2f pos);
        void setPosition(const float x, const float y);
        void setHp(const int hp);
        void loseHp(const int value);

        //Funciones
        void move(const float dirX , const float dirY);
        const bool canAttack();

        void updateAttack();
        void update();
        void render(sf::RenderTarget& target);

        
};


#endif  //PLAYER_H
