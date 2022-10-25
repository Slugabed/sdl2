//Using SDL and standard IO
#include "Game.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 400;

int main(int argc, char* args[])
{
    const int FPS = 60;
    const int TargetFrameTime = 1000/60;
    
    Game game{};
    game.init("Hello!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
    
    Uint32 prevTime = 0;

    while (game.running()) {
        Uint32 startTime = SDL_GetTicks();
        float deltaTime = (startTime - prevTime) / 1000.f;
        prevTime = startTime;
        
        game.handleEvents();
        game.update(deltaTime);
        game.render();
        
        Uint32 frameTime = SDL_GetTicks() - startTime; 
        if (frameTime <= TargetFrameTime) {
            SDL_Delay(TargetFrameTime - frameTime);
        }
    }
    
    game.clean();
    
    return 0;
}
