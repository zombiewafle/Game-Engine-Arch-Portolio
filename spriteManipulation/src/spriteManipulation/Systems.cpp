
#include <print.h>
#include <FastNoise.h>
#include <SDL2/SDL.h>
#include "Systems.h"
#include <ctime>
#include <cstdlib>
#include <fstream> 
#include <vector>
#include <string>
#include <iostream>

#include "Components.h"
#include "ECS/Entity.h"
#include "ECS/Components.h"
#include "Game/Graphics/TextureManager.h"

SpriteSetupSystem::SpriteSetupSystem(SDL_Renderer* renderer)
    : renderer(renderer) { }

SpriteSetupSystem::~SpriteSetupSystem() {
    auto view = scene->r.view<SpriteComponent>();

    for(auto entity : view) {
        const auto spriteComponent = view.get<SpriteComponent>(entity);
        TextureManager::UnloadTexture(spriteComponent.name, spriteComponent.shader.name);
    }
}

void SpriteSetupSystem::run() {
    auto view = scene->r.view<SpriteComponent>();

    for(auto entity : view) {
        const auto spriteComponent = view.get<SpriteComponent>(entity);
        TextureManager::LoadTexture(spriteComponent.name, renderer, spriteComponent.shader);
    }
}

void SpriteRenderSystem::run(SDL_Renderer* renderer) {
    auto view = scene->r.view<TransformComponent, SpriteComponent>();

    for(auto entity : view) {
        const auto spriteComponent = view.get<SpriteComponent>(entity);
        const auto transformComponent = view.get<TransformComponent>(entity);
  
        Texture* texture = TextureManager::GetTexture(spriteComponent.name, spriteComponent.shader.name);
  
        SDL_Rect clip = {
            spriteComponent.xIndex * spriteComponent.size,
            spriteComponent.yIndex * spriteComponent.size,
            spriteComponent.size,
            spriteComponent.size
        };

        int scale = 5;

        texture->render(
            transformComponent.x * scale,
            transformComponent.y * scale,
            48 * scale,
            48 * scale,
            &clip
        );
    }
}

void SpriteUpdateSystem::run(double dT) {
    auto view = scene->r.view<SpriteComponent>();

    Uint32 now = SDL_GetTicks();

    for(auto entity : view) {
        auto& spriteComponent = view.get<SpriteComponent>(entity);

        if (spriteComponent.animationFrames > 0) {
            float timeSinceLastUpdate = now - spriteComponent.lastUpdate;

            int framesToUpdate = static_cast<int>(
                timeSinceLastUpdate / 
                spriteComponent.animationDuration * spriteComponent.animationFrames
            );

            if (framesToUpdate > 0) {
                spriteComponent.xIndex += framesToUpdate;
                spriteComponent.xIndex %= spriteComponent.animationFrames;
                spriteComponent.lastUpdate = now;            
            }
        }
    }
}

TilemapSetupSystem::TilemapSetupSystem(SDL_Renderer* renderer)
    : renderer(renderer) { 
        noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        offsetX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        offsetY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        zoom = 20.0f;
    }

TilemapSetupSystem::~TilemapSetupSystem() {
}

void TilemapSetupSystem::run() {
  auto& tilemapComponent = scene->world->get<TilemapComponent>();
  tilemapComponent.width = 50;
  tilemapComponent.height = 38;
  tilemapComponent.tileSize = 16;
  tilemapComponent.tilemap.resize(tilemapComponent.width * tilemapComponent.height);

  Texture* floorTexture = TextureManager::LoadTexture("Tiles/floor1.png", renderer);
  Texture* floorTexture2 = TextureManager::LoadTexture("Tiles/Floor2.png", renderer);
  Texture* floorTexture3 = TextureManager::LoadTexture("Tiles/Floor3.png", renderer);
  Texture* floorTexture4 = TextureManager::LoadTexture("Tiles/Floor4.png", renderer);
  Texture* floorTexture5 = TextureManager::LoadTexture("Tiles/Floor5.png", renderer);
  Texture* defaultTexture = TextureManager::LoadTexture("Tiles/Floor.png", renderer);
  Texture* grassTexture = TextureManager::LoadTexture("Tiles/Grass.png", renderer);
  Texture* nTexture = TextureManager::LoadTexture("Tiles/N.png", renderer);
  Texture* sTexture = TextureManager::LoadTexture("Tiles/S.png", renderer);
  Texture* eTexture = TextureManager::LoadTexture("Tiles/E.png", renderer);
  Texture* oTexture = TextureManager::LoadTexture("Tiles/W.png", renderer);
  Texture* neTexture = TextureManager::LoadTexture("Tiles/NE.png", renderer);
  Texture* noTexture = TextureManager::LoadTexture("Tiles/NO.png", renderer);
  Texture* seTexture = TextureManager::LoadTexture("Tiles/SE.png", renderer);
  Texture* soTexture = TextureManager::LoadTexture("Tiles/SW.png", renderer);

   std::ifstream mapFile("assets/Maps/Map1.txt"); 
   std::string line;
   int y = 0; 
   std::vector<Texture*> floorTextures = {floorTexture,floorTexture, defaultTexture, floorTexture, floorTexture4, floorTexture4, floorTexture2, floorTexture3 }; 
   FastNoiseLite noise;

   noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
   std::srand(static_cast<unsigned int>(std::time(nullptr)));
   float offsetX = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
   float offsetY = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
   float zoom = 20.0f;


    if (mapFile.is_open()) {
        while (std::getline(mapFile, line)) {
            for (size_t x = 0; x < line.size(); x++) { 
                int index = y * tilemapComponent.width + x;
                Tile& tile = tilemapComponent.tilemap[index];
                
                switch (line[x]) {
                    case '0': tile.type = DungeonTileType::Wall_N; tile.texture = nTexture; break;
                    case '1': tile.type = DungeonTileType::Wall_S; tile.texture = sTexture; break;
                    case '2': tile.type = DungeonTileType::Wall_E; tile.texture = eTexture; break;
                    case '3': tile.type = DungeonTileType::Wall_W; tile.texture = oTexture; break;
                    case '4': tile.type = DungeonTileType::Wall_NW; tile.texture = noTexture; break;
                    case '5': tile.type = DungeonTileType::Wall_SW; tile.texture = soTexture; break;
                    case '6': tile.type = DungeonTileType::Wall_NE; tile.texture = neTexture; break;
                    case '7': tile.type = DungeonTileType::Wall_SE; tile.texture = seTexture; break;
                    case '8':
                      tile.type = DungeonTileType::Floor;
                      tile.texture = floorTextures[rand() % floorTextures.size()];
                      break;
                    default: 
                      tile.texture = defaultTexture; 
                      break;
                }
            }
            y++; 
        }
        mapFile.close();
    } else {
        std::cerr << "Unable to open file";
    }

}



void TilemapRenderSystem::run(SDL_Renderer* renderer) {
    auto& tilemapComponent = scene->world->get<TilemapComponent>();
    int width = tilemapComponent.width;
    int height = tilemapComponent.height;
    int size = tilemapComponent.tileSize;
    int scale = 5;
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Tile& tile = tilemapComponent.tilemap[y * width + x];
            // Asegúrate de que el puntero a la textura no es nulo antes de intentar renderizarlo
            if (tile.texture) {
                tile.texture->render(
                    x * size * scale,  // Posición X en píxeles
                    y * size * scale,  // Posición Y en píxeles
                    size * scale,      // Ancho del tile (posiblemente escalado)
                    size * scale,      // Alto del tile (posiblemente escalado)
                    nullptr,           // SDL_Rect* clip (puede ser nullptr si no necesitas clipping)
                    0.0,               // Ángulo de rotación
                    nullptr,           // Centro de rotación (puede ser nullptr si no necesitas rotación)
                    SDL_FLIP_NONE      // Reflejo (puedes usar SDL_FLIP_HORIZONTAL o SDL_FLIP_VERTICAL si es necesario)
                );
            }
        }
    }
}

void PlayerInputEventSystem::run(SDL_Event event) {
    auto& playerMovement = scene->player->get<SpeedComponent>();
    int speed = 80;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                playerMovement.x = -speed;
                break;
            case SDLK_RIGHT:
                playerMovement.x = speed;
                break;
            case SDLK_UP:
                playerMovement.y = -speed;
                break;
            case SDLK_DOWN:
                playerMovement.y = speed;
                break;
        }
   }
    else if (event.type == SDL_KEYUP) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
            case SDLK_RIGHT:
                playerMovement.x = 0;
                break;
            case SDLK_UP:
            case SDLK_DOWN:
                playerMovement.y = 0;
                break;
        }
    }
}

void PlayerSpriteUpdateSystem::run(double dT) {
    auto& playerMovement = scene->player->get<SpeedComponent>();
    auto& playerSprite = scene->player->get<SpriteComponent>();

    if (playerMovement.x < 0) {
        playerSprite.yIndex = 7;
    }
    else if (playerMovement.x > 0) {
        playerSprite.yIndex = 6;
    }
    else if (playerMovement.y < 0) {
        playerSprite.yIndex = 5;
    }
    else if (playerMovement.y > 0) {
        playerSprite.yIndex = 4;
    }
    else {
        if (playerSprite.yIndex == 7) {
            playerSprite.yIndex = 2;
        }
        else if (playerSprite.yIndex == 6) {
            playerSprite.yIndex = 3;
        }
        else if (playerSprite.yIndex == 5) {
            playerSprite.yIndex = 1;
        }
        else if (playerSprite.yIndex == 4) {
            playerSprite.yIndex = 0;
        }
    }
}

void MovementUpdateSystem::run(double dT) {
  const auto view = scene->r.view<TransformComponent, SpeedComponent>();
  for (const entt::entity e : view) {
    auto& pos = view.get<TransformComponent>(e);
    const auto vel = view.get<SpeedComponent>(e);

    pos.x += vel.x * dT;
    pos.y += vel.y * dT;
  }
}






/* void AutoTilingSetupSystem::run() {
    // Suponiendo que TilemapComponent tiene una matriz o vector de Tiles y cada Tile sabe su tipo.
    auto& tilemapComponent = scene->world->get<TilemapComponent>();

    // Recorres cada tile en el mapa.
    for (int y = 0; y < tilemapComponent.height; ++y) {
        for (int x = 0; x < tilemapComponent.width; ++x) {
            // Obtienes el tile actual y sus vecinos.
            Tile& currentTile = tilemapComponent.getTile(x, y);
            Tile* topNeighbor = tilemapComponent.getTile(x, y - 1);
            Tile* bottomNeighbor = tilemapComponent.getTile(x, y + 1);
            Tile* leftNeighbor = tilemapComponent.getTile(x - 1, y);
            Tile* rightNeighbor = tilemapComponent.getTile(x + 1, y);

            // Lógica para determinar qué textura usar basada en los vecinos.
            // Esto es un ejemplo simplificado y tendrás que adaptar la lógica al diseño de tu juego.
            if (currentTile.type == TileType::Grass) {
                if (topNeighbor && topNeighbor->type == TileType::Water) {
                    currentTile.borderType = TileBorderType::Top;
                } else if (bottomNeighbor && bottomNeighbor->type == TileType::Water) {
                    currentTile.borderType = TileBorderType::Bottom;
                } // y así sucesivamente para los demás vecinos...
            }

            // La asignación real de la textura se puede hacer aquí o durante el renderizado.
            // Si se hace aquí, tendrás que acceder al gestor de texturas y asignar la textura correspondiente.
            switch (currentTile.borderType) {
                case TileBorderType::Top:
                    currentTile.texture = TextureManager::GetTexture("GrassWaterTopBorderTexture", renderer);
                    break;
                case TileBorderType::Bottom:
                    currentTile.texture = TextureManager::GetTexture("GrassWaterBottomBorderTexture", renderer);
                    break;
                // y así sucesivamente para los demás tipos de bordes...
            }
        }
    }
}
 */