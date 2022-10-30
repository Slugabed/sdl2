//
//  Game.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 23.10.22..
//

#pragma once

#include <cstdio>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class Game {
    public :
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running() {
        return isRunning;
    }
    
    static SDL_Renderer *renderer;
private:
    bool isRunning = false;
    int cnt = 0;
    SDL_Window *window;
};
