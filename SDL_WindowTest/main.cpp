//Using SDL and standard IO
#include "Game.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    Game game{};
    game.init("Hello!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);
    
    while (game.running()) {
        game.handleEvents();
        game.update();
        game.render();
    }
    
    game.clean();

    return 0;
}
