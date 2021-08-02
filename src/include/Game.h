/*
    Class that acts as the game engine.
    Wrapper Class
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "Enemies.h"
class Game
{
private:
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;

    //Menus
    Menu startMenu;
    PauseMenu pauseMenu;
    Menu deathMenu;

    //Background
    sf::Texture backgroundTexture;
    sf::Sprite background;

    //Mouse  positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    //Resources
    sf::Font font;
    //Text
    sf::Text uiText;

    //Game logic
    bool endGame;
    //unsigned points;
    //int health;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;

    //Jugador - la nave
    Player player;

    //Game objects
    Enemies virus;
    //Private functions
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initSound();

public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;
    const bool getEndGame() const;

    //Functions
    //void spawnEnemy();

    void pollEvents();
    void updateMousePosition();
    void updateText();
    //void updateEnemies();
    //void updateMenu();

    void update();

    void renderText(sf::RenderTarget &target);
    //void renderEnemies(sf::RenderTarget &target);
    void render();
};

#endif