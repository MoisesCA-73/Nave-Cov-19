#include "Enemies.h"

void Enemies::initVariables()
{
    this->maxEnemies = 5.f;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
}

//sonido de choque bala y virus
void Enemies::initSound()
{
    if (!this->buffer.loadFromFile("Sounds/choque.wav"))
    {
        std::cout << "ERROR::ENEMIES::INITSOUND:: Failed to load sound!" << '\n';
    }
    if (!this->buffer1.loadFromFile("Sounds/choque1.wav"))
    {
        std::cout << "ERROR::ENEMIES::INITSOUND:: Failed to load sound!" << '\n';
    }
    this->sonido.setBuffer(buffer);
    this->sonido1.setBuffer(buffer1);
}

Enemies::Enemies()
{
    this->initVariables();
    this->initSound();
}
void Enemies::spawnEnemy(sf::RenderTarget *target)
{
    //Randomize enemy type
    int type = rand() % 5;

    switch (type)
    {
    case 0:
        this->enemy = std::unique_ptr<VirusAlpha>(new VirusAlpha());
        break;
    case 1:
        this->enemy = std::unique_ptr<VirusBeta>(new VirusBeta());
        break;
    case 2:
        this->enemy = std::unique_ptr<VirusEpsilon>(new VirusEpsilon());
        break;
    case 3:
        this->enemy = std::unique_ptr<VirusGamma>(new VirusGamma());
        break;
    case 4:
        this->enemy = std::unique_ptr<VirusDelta>(new VirusDelta());
        break;
    default:
        this->enemy = std::unique_ptr<VirusDelta>(new VirusDelta());
    }
    this->enemy->getShape().setPosition(static_cast<float>(rand() % static_cast<int>(target->getSize().x - this->enemy->getShape().getSize().x)), -100.f);
    this->enemies.push_back(std::move(this->enemy));
}

void Enemies::update(sf::RenderTarget *target, Player &player)
{
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->spawnEnemy(target);
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }
    for (int i = 0; i < this->enemies.size(); i++)
    {
        this->enemies[i]->getShape().move(0.f, 1.f * this->enemies[i]->getMovementS());
        if (this->enemies[i]->getPos().y > target->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            i--;
            player.getHp() -= 1;
        }
    }
    
    for (int i = 0; i < this->enemies.size(); i++)
    {
        if (this->enemies[i]->getShape().getGlobalBounds().contains(player.getShape().getPosition()))
        {
            player.Danio(1); //solo quita 1 de vida por el momento cuando choca con un virus
            this->sonido1.setVolume(3);//Volumen, no elevar a mas de 10 :)
            this->sonido1.play();
            this->enemies.erase(this->enemies.begin() + i);
        }
       
        bool deleted = false;
        for (int j = 0; j < player.getBullet().getBullets().size() && deleted == false; j++)
        {
            //When there is contact between a bullet and an enemy
            if (this->enemies[i]->getShape().getGlobalBounds().contains(player.getBullet().getBullets()[j].getPosition()))
            {
                this->enemies[i]->setHealth(this->enemies[i]->getHealth() - player.getBullet().getDamage());
                //player.getBullet().getBullets().erase(player.getBullet().getBullets().begin() + j);
                player.bullet.bullets.erase(player.bullet.bullets.begin() + j);
                j--;
                deleted = true;
                if (this->enemies[i]->getHealth() <= 0.f)
                {
                    player.setPoints(player.getPoints() + this->enemies[i]->getPoints());
                    this->enemies.erase(this->enemies.begin() + i);
                    i--;
                    this->sonido.setVolume(3);//Volumen, no elevar a mas de 10 :)
                    this->sonido.play();
                    this->sonido.setVolume(3);//Volumen, no elevar a mas de 10 :)
                    this->sonido.play();
                    break;
                }
            }
        }
    }
}

void Enemies::render(sf::RenderTarget *target)
{
    for (auto &e : this->enemies)
    {
        target->draw(e->getShape());
    }
}
