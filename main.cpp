#include "Game.h"

using namespace sf;

int main()
{

    //Inicializa rand
    std::srand(static_cast<unsigned>(time(NULL)));

    //Inicializa game engine
    Game game;

    //Ciclo del juego
    while (game.running() && !game.getEndGame())
    {
        //Update
        game.update();
        //Render
        game.render();
    }
    //Fin de la aplicacion
    return 0;
}