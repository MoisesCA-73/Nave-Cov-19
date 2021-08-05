#include "Bullet.h"

void Bullet::initVariables()
{
    this->movementSpeed = 20.f;
    this->shape.setTexture(&this->bulletTexture);
    this->size = sf::Vector2f(20.f, 40.f);
    this->shape.setSize(this->size);
    this->fireRate = 10.f;
    this->fireRateCount = this->fireRate;
    this->fireRateMax = 4.9;
    this->damage = 50;
    this->isDFR = false;
}

void Bullet::initTexture()
{
    if (!this->bulletTexture.loadFromFile("Textures/bullet-temporary.png"))
    {
        std::cout << "ERROR::BULLET::INITTEXTURE:: Failed to load texture!" << '\n';
    }
}

//sonido de disparo
void Bullet::initSound()
{
    if (!this->buffer.loadFromFile("Sounds/disparo.wav"))
    {
        std::cout << "ERROR::ENEMIES::INITSOUND:: Failed to load sound!" << '\n';
    }
    this->sonido.setBuffer(buffer);
}

Bullet::Bullet()
{
    this->initTexture();
    this->initVariables();
    this->initSound();
}

Bullet::~Bullet()
{
}

float Bullet::getFireRate() const
{
    return this->fireRate;
}
int Bullet::getDamage() const
{
    return this->damage;
}

std::vector<sf::RectangleShape> Bullet::getBullets() const
{
    return this->bullets;
}
void Bullet::setFireRate(float fireRate)
{
    if (!(fireRate < fireRateMax)){
        this->fireRate = fireRate;
    }
    this->DFRtimer = 500.f;
    this->isDFR = true;
}

void Bullet::shoot(sf::Vector2f coord)
{

    this->shape.setPosition(coord.x + 12.5, coord.y);
    this->bullets.push_back(this->shape);
}

void Bullet::updateBullets()
{
    for (size_t i = 0; i < this->bullets.size(); i++)
    {

        this->bullets[i].move(0.f, -movementSpeed);

        if (this->bullets[i].getPosition().y + this->bullets[i].getSize().y < 0.f)
        {
            this->bullets.erase(this->bullets.begin() + i);
            i--;
        }
    }
}
void Bullet::updateInput(sf::Vector2f coord)
{
    if (this->fireRateCount >= this->fireRate)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            this->shoot(coord);
            this->fireRateCount = 0.f;
            this->sonido.setVolume(2); //Volumen, no elevar a mas de 10 :)
            this->sonido.play();
        }
    }
    else
    {
        this->fireRateCount += 1.f;
    }
}

//Funciones publicas

//Cuando dispara
void Bullet::update(sf::Vector2f coord)
{
    this->updateInput(coord);
    this->updateBullets();
    if (isDFR)
    {
        this->DFRtimer -= 1.f;
        if (this->DFRtimer <= 0)
        {
            this->isDFR = false;
            this->fireRate = 10.f;
        }
    }
}

void Bullet::render(sf::RenderTarget *target)
{
    for (auto &e : bullets)
    {
        target->draw(e);
    }
}
