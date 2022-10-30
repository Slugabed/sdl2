//
//  Map.hpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#pragma once

#include <cstdio>
#include "Game.hpp"
#include <vector>

using MapArr = std::vector<std::vector<int>>;

const int WIDTH = 25;
const int HEIGHT = 20;

class Map {
public:
    Map();
    ~Map();
    
    void LoadMap(MapArr);
    void DrawMap();
    
private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    MapArr map;
};
