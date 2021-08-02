#include "PauseMenu.h"

#include <iostream>

PauseMenu::PauseMenu()
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

    menu[0].setString("Continue");
    menu[1].setString("Retry");
    menu[2].setString("Exit");

    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setPosition(sf::Vector2f((400 - (menu[i].getGlobalBounds().width / 2)), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));
    }

    this->isOpened = true;
    this->closeGame = false;
}

PauseMenu::~PauseMenu()
{
}
//Accesors
bool PauseMenu::getIsOpened() const
{
    return isOpened;
}
bool PauseMenu::getCloseGame() const
{
    return closeGame;
}
//functions
void PauseMenu::setIsopened(bool initiate)
{
    this->isOpened = initiate;
}
void PauseMenu::update(const sf::RenderTarget *target, sf::Vector2f mousePosView)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        if (this->menu[0].getGlobalBounds().contains(mousePosView))
        {
            menu[0].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //this->selectedItemIndex = i;
                this->isOpened = false;
            }
        }
        else if (this->menu[1].getGlobalBounds().contains(mousePosView))
        {
            menu[1].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                //this->selectedItemIndex = i;
                this->isOpened = false;
            }
        }
        else if (this->menu[2].getGlobalBounds().contains(mousePosView))
        {
            menu[2].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->closeGame = true;
            }
        }
        else
        {
            menu[i].setFillColor(sf::Color::White);
        }
    }
}
void PauseMenu::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}