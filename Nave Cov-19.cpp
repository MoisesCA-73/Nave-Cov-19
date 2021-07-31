/*
Main App for Nave Cov-19 game

Es main.cpp pero con lo nuevo que tenemos 
*/

#include "Game.h"

int main()
{
    //Initialize random seed
    std::srand(static_cast<unsigned>(time(NULL)));

    //Initialize game engine
    Game game;
    
    std::cout << "Game created succesfully" << '\n';

    //Game loop
    while (game.running() && !game.getEndGame())
    {
        //Update
        game.update();
        //Render
        game.render();
    }
    //End of application
    return 0;
}