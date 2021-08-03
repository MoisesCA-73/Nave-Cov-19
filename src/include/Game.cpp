#include "Game.h"

//Private functions

void Game::initVariables()
{
    this->window = nullptr;

    //Game Logic
    this->endGame = false;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::initWindow()
{
    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "Nave Cov-19", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    sf::Image icon;
    icon.loadFromFile("Textures/virus.png");
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Game::initFonts()
{
    if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
    {
        std::cout << "ERROR::GAME::INITFONTS:: Failed to load font!"
                  << "\n";
    }
}

void Game::initText()
{
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(32);
    this->uiText.setFillColor(sf::Color::White);
    this->uiText.setString("NONE");
}

void Game::initBackground()
{
    if (!this->backgroundTexture.loadFromFile("Textures/background.jpg"))
    {
        std::cout << "ERROR::GAME::INITBACKGROUND:: Failed to load texture!"
                  << "\n";
    }

    this->background.setTexture(this->backgroundTexture);
    this->background.setScale((float)this->window->getSize().x / backgroundTexture.getSize().x, 
                              (float)this->window->getSize().y / backgroundTexture.getSize().y);
}

//Constructors / Destructors

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
    this->initBackground();
}

Game::~Game()
{
    delete this->window;
}

//Accessors
const bool Game::running() const
{
    return this->window->isOpen();
}

const bool Game::getEndGame() const
{
    return this->endGame;
}

//Functions here

void Game::pollEvents()
{
    //Events polling
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
            {
                this->pauseMenu.setIsopened(true);
            }
            break;
        }
    }
}

void Game::updateMousePosition()
{
    /*
    @ return void

    Updates mouse position:
        * Mouses position relative to window (Vector2i)
    */

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateText()
{
    std::stringstream ss;

    ss << "Points: " << this->player.getPoints() << "\n"
       << "Health: " << this->player.getHp() << "\n";

    this->uiText.setString(ss.str());
}

void Game::update()
{
    /*
        Updates the game during the game loop
    */
    this->pollEvents();

    this->updateMousePosition();

    if (this->startMenu.getIsOpened())
    {
        this->startMenu.update(this->window, this->mousePosView);
        if (this->startMenu.getCloseGame())
        {
            this->endGame = this->startMenu.getCloseGame();
        }
    }
    else if (this->pauseMenu.getIsOpened())
    {
        this->pauseMenu.update(this->window, this->mousePosView);
        if (this->pauseMenu.getCloseGame())
        {
            this->endGame = this->pauseMenu.getCloseGame();
        }
        else if (this->pauseMenu.getRetry())
        {
            this->restart();
        }
    }
    else
    {
        if (this->deathMenu.getIsOpened())
        {
            this->deathMenu.update(this->window, mousePosView);
            if (this->deathMenu.getCloseGame())
            {
                this->endGame = this->deathMenu.getCloseGame();
            }
            else if (this->deathMenu.getRetry())
            {
                this->restart();
            }
        }
        else if (this->player.getHp() <= 0)
        {
            this->deathMenu.setIsopened(true);
        }
        else if (!this->endGame)
        {

            this->updateText();

            this->player.update(this->window);
            this->virus.update(this->window, this->player);
        }
    }
}

void Game::restart()
{
    this->player.setHP(30);
    this->player.setPoints(0);
    this->virus.enemies.clear();
}

void Game::renderText(sf::RenderTarget &target)
{
    target.draw(this->uiText);
}

void Game::render()
{
    /*
        - clear old frame
        - render objects
        - display from in window

        Renders the game objects
    */
    this->window->clear();

    if (this->startMenu.getIsOpened())
    {
        this->startMenu.draw(*this->window);
    }
    else if (this->pauseMenu.getIsOpened())
    {
        this->pauseMenu.draw(*this->window);
    }
    else if (this->deathMenu.getIsOpened())
    {
        this->deathMenu.draw(*this->window);
    }
    else
    {
        //Draw game objects
        this->window->draw(background);
        this->renderText(*this->window);

        this->player.render(this->window);
        this->virus.render(this->window);
    }

    this->window->display();
}