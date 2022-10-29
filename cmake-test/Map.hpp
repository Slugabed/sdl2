//
//  Map.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Game.hpp"

class Map {
public:
    Map();
    ~Map();
    
    void LoadMap();
    void DrawMap();
    
private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};

#endif /* Map_hpp */
