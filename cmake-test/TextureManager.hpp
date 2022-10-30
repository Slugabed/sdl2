//
//  TextureManager.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <cstdio>
#include "Game.hpp"

class TextManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif /* TextureManager_hpp */
