#include "Player.h"

void Player::initVariables(){
    this->movementSpeed = 5.f;
    
    this->attackCooldownMax = 10.f;
    this->attackCooldown = this->attackCooldownMax;

    this->hpMax = 100;
    this->hp = this->hpMax;
}

void Player::initTexture(){
    //Load a texture from file
    if(!this->playerTexture.loadFromFile("Textures/nave.png")){//direccion de archivo donde esta la imagen de la nave
        std::cout<<"Error::Player::Inittexture::could not load texture file."<<std::endl;
    }

}

void Player::initSprite(){
    this->sprite.setTexture(this->playerTexture);

    //Cambiar el tamaño
    this->sprite.scale(0.2f, 0.2f);  
}

 Player:: Player(){
    this->initVariables();
    this->initTexture();
    this->initSprite();
}

 Player::~Player(){

}

const sf::Vector2f & Player::getPos() const{
    return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const{
    return this->sprite.getGlobalBounds();
}

const int & Player::getHp() const{
    return this->hp;
}

const int & Player::getHpMax() const{
    return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos){
    this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y){
    this->sprite.setPosition(x,y);
}

void Player::setHp(const int hp){
    this->hp= hp;
}

void Player::loseHp(const int value){
    this->hp -=value;
    if(this->hp < 0){
        this->hp = 0 ;
    }
}

//Functions
void Player::move(const float dirX, const float dirY){
    this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const bool Player::canAttack(){
    if(this->attackCooldown >= this->attackCooldownMax){
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

void Player::updateAttack(){
    if(this->attackCooldown < this->attackCooldownMax){
        this->attackCooldown += 0.5f;
    }
}

void Player::update(){
    this->updateAttack();
}

//Representa nuestro sprite
void Player::render(sf::RenderTarget& target){
    target.draw(this->sprite);

}
