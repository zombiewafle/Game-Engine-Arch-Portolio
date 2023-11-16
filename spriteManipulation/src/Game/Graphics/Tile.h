#pragma once

#include "Game/Graphics/Texture.h"
#include "Game/Graphics/DungeonTileType.h"


struct Tile {
  Texture* texture = nullptr;  
  DungeonTileType type;
};
