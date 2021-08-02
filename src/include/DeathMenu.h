#ifndef DEATHMENU_H
#define DEATHMENU_H
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class DeathMenu
{
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

    sf::Text mensaje;

    bool isOpened;
    bool closeGame;
    bool retry;

public:
    //Constructor - Destructor
    DeathMenu();
    //Accesors
    bool getIsOpened() const;
    bool getCloseGame() const;
    bool getRetry() const;
    //Functions
    void setIsopened(bool initiate);
    void update(const sf::RenderTarget *target, sf::Vector2f mousePosView);
    void draw(sf::RenderWindow &window);
};

#endif