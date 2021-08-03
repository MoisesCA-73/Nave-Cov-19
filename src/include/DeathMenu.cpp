#include "DeathMenu.h"
#include <iostream>
DeathMenu::DeathMenu()
{
    if (!this->font.loadFromFile("Fonts/Debug.ttf"))
    {
        std::cout << "ERROR::DEATH::INITFONTS:: Failed to load font!" << '\n';
    }
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        sf::Text text;
        text.setFont(this->font);
        text.setCharacterSize(64);
        text.setFillColor(sf::Color::White);
        this->menu.push_back(text);
    }
    menu[0].setString("YOU ARE INFECTED");
    menu[1].setString("Retry");
    menu[2].setString("Exit");

    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        menu[i].setPosition(sf::Vector2f((400 - (menu[i].getGlobalBounds().width / 2)), 600 / (MAX_NUMBER_OF_ITEMS + 1) * (i + 1)));
    }
    this->retry = false;
    this->isOpened = false;
    this->closeGame = false;
}

bool DeathMenu::getIsOpened() const
{
    return this->isOpened;
}

bool DeathMenu::getCloseGame() const
{
    return this->closeGame;
}

bool DeathMenu::getRetry() const
{
    return this->retry;
}

void DeathMenu::setIsopened(bool initiate)
{
    this->isOpened = initiate;
}

void DeathMenu::update(const sf::RenderTarget *target, sf::Vector2f mousePosView)
{
    for (int i = 1; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        if (this->menu[i].getGlobalBounds().contains(mousePosView))
        {
            menu[i].setFillColor(sf::Color::Red);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->selectedItemIndex = i;
                if (this->selectedItemIndex == 1)
                {
                    this->retry = true;
                    this->isOpened = false;
                }
                else if (this->selectedItemIndex == 2)
                {
                    this->closeGame = true;
                }
            }
        }
        else
        {
            menu[i].setFillColor(sf::Color::White);
        }
    }
}

void DeathMenu::draw(sf::RenderWindow &window)
{
    for (size_t i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(this->menu[i]);
    }
}
