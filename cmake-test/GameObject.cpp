//
//  GameObject.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* texturesheet, int xpos, int ypos) {
    GameObject::xpos = xpos;
    GameObject::ypos = ypos;
    objTexture = TextManager::LoadTexture(texturesheet);
    std::cout << objTexture << std::endl;
}

void GameObject::Update() {
    xpos++;
    ypos++;
    srcRect.h = 240;
    srcRect.w = 160;
    srcRect.x = 0;
    srcRect.y = 0;
    
    destRect.h = srcRect.h * 0.5;
    destRect.w = srcRect.w * 0.5;
    destRect.x = xpos;
    destRect.y = ypos;
}

void GameObject::Render() {
    SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
