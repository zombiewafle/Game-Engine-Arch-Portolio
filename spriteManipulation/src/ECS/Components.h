#pragma once

#include <glm/glm.hpp>
#include <string>
#include <vector>

#include <Game/Graphics/PixelShader.h>
#include "Game/Graphics/Tile.h"
#include "Game/Graphics/DungeonTileType.h"

struct NameComponent {
  std::string tag;
};

struct TransformComponent {
  // glm::ivec2 position;
  // glm::vec2 scale;
  // double rotation;
  int x;
  int y;
};

struct SpeedComponent {
  int x;
  int y;
};

struct MovementComponent {
  glm::vec2 velocity;
};

struct SpriteComponent {
  std::string name;
  int xIndex = 0;
  int yIndex = 0;
  int size = 48;
  int animationFrames = 0;
  int animationDuration = 0;
  PixelShader shader = { nullptr, "" };

  Uint32 lastUpdate = 0;
};

struct TilemapComponent {
  std::vector<Tile> tilemap;
  int width;
  int height;
  int tileSize;
  std::vector<DungeonTileType> tileTypes; 
};