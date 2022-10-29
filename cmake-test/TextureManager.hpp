//
//  TextureManager.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "Game.hpp"

class TextManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName);
};

#endif /* TextureManager_hpp */
