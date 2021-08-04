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
#include "DeathMenu.h"
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
    DeathMenu deathMenu;

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

    //Music
    sf::Music music;
    
    //Game logic
    bool endGame;
    
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    //Jugador - la nave
    Player player;

    //Game objects
    Enemies virus;
    //Items powerups;

    //Private functions
    void initVariables();
    void initWindow();
    void initFonts();
    void initText();
    void initSound();
    void initBackground();

public:
    //Constructors / Destructors
    Game();
    virtual ~Game();

    //Accessors
    const bool running() const;     //Returns true if the windows is opened
    const bool getEndGame() const;  //Returns true if the game has finished

    //Functions
    void pollEvents();
    void updateMousePosition();
    void updateText();
    void update();
    void restart();
    void renderText(sf::RenderTarget &target);
    void render();
};

#endif