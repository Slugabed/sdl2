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
    if(fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING)==0) {
        std::cout << "Subsystems Initialised!..." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "Window created!" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
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
    SDL_RenderClear(renderer);
    player->Render();
    enemy->Render();
    SDL_RenderPresent (renderer) ;
}

void Game::update() {
    player->Update();
    enemy->Update();
}

Game::Game() {}
Game::~Game() {}
