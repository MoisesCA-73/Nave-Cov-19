#include <iostream>
#include "Menu.h"

Menu::Menu(float width, float height)
{
    if(!this->font.loadFromFile("Fonts/Dosis-Light"))
    {
        std::cout << "ERROR::GAME::INITFONTS:: Failed to load font!" << '\n';
    }

    for(size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setFont(this->font);
        menu[0].setColor(sf::Color::White);
        menu[i].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1)*1));
    }
    menu[0].setString("Jugar");
    menu[1].setString("Opciones");
    menu[2].setString("Salir");

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
    for(size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}