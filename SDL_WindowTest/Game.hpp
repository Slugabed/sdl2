//
//  Game.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 23.10.22..
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <filesystem>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#if _WIN32
#include <windows.h>
#endif
#include <gl/GL.h>
#include <gl/GLU.h>
#if _WIN32
#include <SDL2/SDL_image.h>
#else
#include <SDL2_image/SDL_image.h>
#endif

class Game {
public:
    Game();
    ~Game();
    
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    bool initGL();

    void handleEvents();
    void update(float deltaTime);
    void render();
    void clean();
    bool running() {
        return isRunning;
    }
private:
    bool isRunning;
    float time = 0;
    int cnt = 0;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    SDL_GLContext gContext;
};

#endif /* Game_hpp */
