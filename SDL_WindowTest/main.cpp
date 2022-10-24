//Using SDL and standard IO
#include "Game.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* args[])
{
    const int FPS = 60;
    const int FrameTime = 1000/60;
    
    Game game{};
    game.init("Hello!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    while (game.running()) {
        Uint32 startTime = SDL_GetTicks();
        
        game.handleEvents();
        game.update();
        game.render();
        
        Uint32 time = SDL_GetTicks() - startTime;
        if (time <= FrameTime) {
            SDL_Delay(FrameTime - time);
        }
    }
    
    game.clean();
    
    return 0;
}
