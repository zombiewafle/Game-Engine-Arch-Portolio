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

struct RigidbodyComponent {
  glm::vec2 velocity; 
  glm::vec2 acceleration; 
  bool gravity; 
  float mass;
  bool isStatic;
};

struct ColliderComponent {
  int width;
  int height;
  bool isInCollision;
  int offsetX;
  int offsetY;
  bool isPortal;
  bool isPlayer;
  bool isEnemy;

  ColliderComponent(int w, int h, int offsetX = 0, int offsetY = 0, bool isInCollision = false, bool isPortal = false , bool isPlayer = false, bool isEnemy = false)
      : width(w), height(h), offsetX(offsetX), offsetY(offsetY), isInCollision(isInCollision), isPortal(isPortal), isPlayer(isPlayer), isEnemy(isEnemy) {}
};

struct Health_DamageComponent{
  int healthBar;
  int damage;

  Health_DamageComponent(int health, int dam): healthBar(health), damage(dam){}
};