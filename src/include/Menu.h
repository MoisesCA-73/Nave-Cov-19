/*
    Game's start menu
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#define MAX_NUMBER_OF_ITEMS 3
class Menu
{
private:
    int seelctedItemIndex;
    sf::Font font;
    std::vector<sf::Text> menu;

public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
};
#endif  //MENU_H