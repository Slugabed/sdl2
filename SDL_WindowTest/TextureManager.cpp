//
//  TextureManager.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#include "TextureManager.hpp"

SDL_Texture* TextManager::LoadTexture(const char *fileName, SDL_Renderer *renderer) {
    SDL_Surface *tmpSurface = IMG_Load(fileName);
    if (tmpSurface == NULL)
    {
        std::cout << "Can't load image " << fileName << "!" << std::endl;
        return NULL;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    if (texture == NULL)
    {
        std::cout << "Can't create texture for " << fileName << "!" << std::endl;
        return NULL;
    }

    // This line break Windows build
    //SDL_FreeSurface(tmpSurface);
    
    return texture;
}
