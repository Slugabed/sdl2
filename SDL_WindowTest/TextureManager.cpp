//
//  TextureManager.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#include "TextureManager.hpp"

SDL_Texture* TextManager::LoadTexture(const char *fileName, SDL_Renderer *renderer) {
    SDL_Surface *tmpSurface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return texture;
}
