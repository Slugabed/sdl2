//
//  GameObject.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Game.hpp"

class GameObject {
public:
    GameObject(const char* texturesheet, SDL_Renderer *renderer, int xpos, int ypos);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    int xpos;
    int ypos;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer *renderer;
};

#endif /* GameObject_hpp */
