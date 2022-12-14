//
//  TextureManager.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#include "TextureManager.hpp"

SDL_Texture* TextManager::LoadTexture(const char *fileName) {
    SDL_Surface *tmpSurface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    
    return texture;
}

void TextManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
