//
//  Game.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 23.10.22..
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

namespace fs = std::filesystem;

GameObject *player, *enemy;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    flags |= SDL_WINDOW_OPENGL;

    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0) {
        std::cout << "Subsystems Initialised!..." << std::endl;

        //Use OpenGL 2.1
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        //Create context
        gContext = SDL_GL_CreateContext(window);
        if (gContext)
        {
            std::cout << "GL context created!" << std::endl;

            //Use Vsync
            if (SDL_GL_SetSwapInterval(1) < 0)
            {
                printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
            }

            //Initialize OpenGL
            if (initGL())
            {
                std::cout << "OpenGL initialized!" << std::endl;
            }
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    fs::path image_path;

    image_path = "Resources";
    image_path /= "hero.png";
    player = new GameObject(image_path.string().c_str(), renderer, 0, 0);

    image_path = "Resources";
    image_path /= "enemy.png";
    enemy = new GameObject(image_path.string().c_str(), renderer, 50, 50);
}

bool Game::initGL()
{
    bool success = true;
    GLenum error = GL_NO_ERROR;

    //Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 0.1f, 10.0f);

    //Check for error
    error = glGetError();
    if (error != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL! %s\n", gluErrorString(error));
        success = false;
    }

    //Initialize Modelview Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //Check for error
    error = glGetError();
    if (error != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL! %s\n", gluErrorString(error));
        success = false;
    }

    //Initialize clear color
    glClearColor(0.f, 0.f, 0.f, 1.f);

    //Check for error
    error = glGetError();
    if (error != GL_NO_ERROR)
    {
        printf("Error initializing OpenGL! %s\n", gluErrorString(error));
        success = false;
    }

    return success;
}

void Game:: handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}

void Game::render() {
    float n;
    bool mode = modff(time * 0.5f, &n) > 0.5f;

    if (mode)
        SDL_RenderClear(renderer);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    player->Render();
    enemy->Render();

    glBegin(GL_LINE_LOOP);
    std::cout << time << std::endl;
    for (int i = 0; i < 1000; i++)
    {
        float f = (float)i / 1000 * 3.14f * 2;
        glVertex3f(
            sinf(f * 15 + time * 0.4f), 
            cosf(f * 20 + time * 0.7f), 
            cosf(f * 12) - 1.2f);
    }
    glEnd();

    if (mode)
        SDL_RenderPresent(renderer);
    else
        //Update screen
        SDL_GL_SwapWindow(window);
}

void Game::update(float deltaTime) {
    time += deltaTime;
    player->Update();
    enemy->Update();
}

Game::Game() {}
Game::~Game() {}
