//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Event event;
    bool quit = false;
    while(!quit) {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT) quit = true;
      if (event.window.event == SDL_WINDOWEVENT_ENTER) SDL_Log("Focus gained");
      if (event.window.event == SDL_WINDOWEVENT_LEAVE) SDL_Log("Focus lost");
      if (event.window.event == SDL_WINDOWEVENT_MOVED) SDL_Log("Moved");
    }

    return 0;
}
