/*
    Game's start menu
*/

#ifndef MENU_H
#define MENU_H

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
private:
    int selectedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

    bool isOpened;

    //Private methods

public:
    Menu();
    ~Menu();

    bool getIsOpened() const;

    void hide();
    void update(const sf::RenderTarget* target, sf::Vector2f mousePosView);
    void draw(sf::RenderWindow &window);
};


#endif  //MENU_H