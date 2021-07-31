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