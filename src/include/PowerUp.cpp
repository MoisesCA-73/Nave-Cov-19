#include "PowerUp.h"

void PowerUp::initVariables(){
    this->movementSpeed = 10.f;
}

void PowerUp::initTexture(){
    //txt
}

void PowerUp::initShape(){
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    
}

sf::RectangleShape &PowerUp::getShape()
{
    return this->shape;
}
//Accessor
const sf::Vector2f &PowerUp::getPos()
{
    return this->shape.getPosition();
}

float PowerUp::getMovementS()
{
    return this->movementSpeed;
}

void PowerUp::makeChange(Player& player){

}
/*
PowerUp::PowerUp(float pos_x, float pos_y){
    this->initShape();
    //this->initTexture();
    this->initVariables();
    
}

PowerUp::~PowerUp(){

}
*/
void PowerUp::update(){

}

void PowerUp::render(sf::RenderTarget * target){
    target->draw(this->shape);
}