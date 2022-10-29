#pragma once

#include <stdio.h>
#include "Game.hpp"

//class GameObject {
//public:
//    GameObject(const char* texturesheet, SDL_Renderer* renderer, int xpos, int ypos);
//    ~GameObject();
//
//    void Update();
//    void Render();
//
//private:
//    int xpos;
//    int ypos;
//    SDL_Texture* objTexture;
//    SDL_Rect srcRect, destRect;
//    SDL_Renderer* renderer;
//};
//
//#endif /* GameObject_hpp */

class Circle
{
public:
    Circle(SDL_Renderer* renderer);

    void SetPosition(SDL_FPoint pos);
    void SetRadius(float radius);

    void Render();

private:
    SDL_Renderer* renderer;
    SDL_FPoint pos;
    float radius;
};

