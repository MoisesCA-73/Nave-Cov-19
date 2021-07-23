#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS:: Failed to load font!" << '\n';
    }
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        sf::Text text;
        text.setFont(this->font);
        text.setCharacterSize(32);
        text.setFillColor(sf::Color::White);
        this->menu.push_back(text);
    }
    menu[0].setString("Jugar");
    menu[0].setPosition(sf::Vector2f((800 / 2) - (menu[0].getLocalBounds().width / 2), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (1)));
    menu[1].setString("Opciones");
    menu[1].setPosition(sf::Vector2f((800 / 2) - (menu[1].getLocalBounds().width / 2), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (2)));
    menu[2].setString("Salir");
    menu[2].setPosition(sf::Vector2f((800 / 2) - (menu[2].getLocalBounds().width / 2), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (3)));

    this->isOpened = true;
}

Menu::~Menu()
{
}
bool Menu::getIsOpened() const
{
    return isOpened;
}
void Menu::setIsopened(bool initiate)
{
    this->isOpened = initiate;
}
void Menu::update(const sf::RenderTarget *target, sf::Vector2f mousePosView)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        if (this->menu[i].getGlobalBounds().contains(mousePosView))
        {
            menu[i].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->selectedItemIndex = i;
                this->isOpened = false;
            }
        }
        else
        {
            menu[i].setFillColor(sf::Color::White);
        }
    }
}
void Menu::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}