//
//  Map.cpp
//  SDL_WindowTest
//
//  Created by Bulat Islamov on 24.10.22..
//

#include "Map.hpp"
#include "TextureManager.hpp"

//int lvl1[20][25] = {
//    {}
//}

Map::Map() {
    dirt = TextManager::LoadTexture("assets/dirt.png");
    grass = TextManager::LoadTexture("assets/grass.png");
    water = TextManager::LoadTexture("assets/water.png");
}

void Map::LoadMap() {
    
}

void Map::DrawMap() {
    
}
