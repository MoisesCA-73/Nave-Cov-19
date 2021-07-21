#include "Game.h"

using namespace sf;

int main()
{

    //Initialize random seed
    std::srand(static_cast<unsigned>(time(NULL)));
    //Initialize game engine
    Game game;

    //Menu

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