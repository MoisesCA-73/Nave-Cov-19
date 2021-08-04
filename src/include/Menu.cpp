#include <iostream>
#include "Menu.h"

Menu::Menu()
{
    if (!this->font.loadFromFile("Fonts/Debug.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS:: Failed to load font!" << '\n';
    }
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        sf::Text text;
        text.setFont(this->font);
        text.setCharacterSize(64);
        text.setFillColor(sf::Color::White);
        this->menu.push_back(text);
    }

    menu[0].setString("Play");
    menu[1].setString("Options");
    menu[2].setString("Exit");

    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setPosition(sf::Vector2f((400 - (menu[i].getGlobalBounds().width / 2)), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));
    }

    this->isOpened = true;
    this->closeGame = false;

    this->menuBuffer.loadFromFile("Sounds/fondo-inicio.wav");
}

Menu::~Menu()
{
}
//Accesors
bool Menu::getIsOpened() const
{
    return isOpened;
}
bool Menu::getCloseGame() const
{
    return closeGame;
}
//functions
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
                if (i == 2)
                {
                    this->closeGame = true;
                }
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
        window.draw(this->menu[i]);
    }
}