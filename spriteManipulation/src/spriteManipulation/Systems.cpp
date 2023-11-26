
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
  tilemapComponent.width = 48;
  tilemapComponent.height = 48;
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
    int scale = 7;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            Tile& tile = tilemapComponent.tilemap[y * width + x];
            
            if (tile.texture) {
                tile.texture->render(
                    x * size * scale,  
                    y * size * scale,  
                    size * scale,      
                    size * scale,      
                    nullptr,           
                    0.0,               
                    nullptr,           
                    SDL_FLIP_NONE      
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
    const auto view = scene->r.view<TransformComponent, SpeedComponent, SpriteComponent>();

    const int windowWidth = 180;  
    const int windowHeight = 135; 

    for (const entt::entity e : view) {
        auto& transform = view.get<TransformComponent>(e);
        const auto& speed = view.get<SpeedComponent>(e);
        const auto& sprite = view.get<SpriteComponent>(e);

        int newX = transform.x + speed.x * dT;
        int newY = transform.y + speed.y * dT;

        int spriteWidth = sprite.size;   
        int spriteHeight = sprite.size;  

        newX = std::max(0, std::min(newX, windowWidth - spriteWidth));
        newY = std::max(0, std::min(newY, windowHeight - spriteHeight));

        transform.x = newX;
        transform.y = newY;
    }
}




/* void PhysicsSystem::run(double dT) {
    const glm::vec2 GRAVITY(0.0f, -9.81f); // Definir la gravedad
    
    auto view = scene->r.view<RigidbodyComponent, TransformComponent>();
    for (const entt::entity e : view) {
        auto& rb = view.get<RigidbodyComponent>(e);
        auto& transform = view.get<TransformComponent>(e);

        if (!rb.isStatic) {
            float deltaTime = static_cast<float>(dT);
            rb.acceleration += GRAVITY * deltaTime;
            rb.velocity += rb.acceleration * deltaTime;
            transform.x += rb.velocity.x * deltaTime;
            transform.y += rb.velocity.y * deltaTime;
            rb.acceleration = glm::vec2(0.0f);

            // Debugging output
            std::cout << "Entity: " << static_cast<uint32_t>(e)
                      << " Position: " << transform.x << ", " << transform.y
                      << " Velocity: " << rb.velocity.x << ", " << rb.velocity.y
                      << " Acceleration: " << rb.acceleration.x << ", " << rb.acceleration.y
                      << std::endl;
        }
    }
}
 */

void CollisionSystem::run(double dT) {
    auto view = scene->r.view<ColliderComponent, TransformComponent>();

    for (auto entity : view) {
        auto& collider = view.get<ColliderComponent>(entity);
        collider.isInCollision = false;
    }

    for (auto itA = view.begin(); itA != view.end(); ++itA) {
        auto entityA = *itA;
        auto& colliderA = view.get<ColliderComponent>(entityA);

        for (auto itB = std::next(itA); itB != view.end(); ++itB) {
            auto entityB = *itB;
            auto& colliderB = view.get<ColliderComponent>(entityB);

            if (checkAABBCollision(view.get<TransformComponent>(entityA), colliderA, view.get<TransformComponent>(entityB), colliderB)) {
                handleCollision(entityA, entityB);
            }
        }
    }
}



bool CollisionSystem::checkAABBCollision(TransformComponent& transformA, ColliderComponent& colliderA,
                                         TransformComponent& transformB, ColliderComponent& colliderB){
    
    if (transformA.x + colliderA.width < transformB.x || transformB.x + colliderB.width < transformA.x) return false;
    
    if (transformA.y + colliderA.height < transformB.y || transformB.y + colliderB.height < transformA.y) return false;
    
    return true;
}



void CollisionSystem::handleCollision(entt::entity entityA, entt::entity entityB) {
    auto& colliderA = scene->r.get<ColliderComponent>(entityA);
    auto& colliderB = scene->r.get<ColliderComponent>(entityB);

    colliderA.isInCollision = true;
    colliderB.isInCollision = true;

    if (colliderA.isPlayer && colliderB.isPortal) {

        std::cout << "Player has collided with a portal!" << std::endl;
        
    } else if (colliderB.isPlayer && colliderA.isPortal) {
        std::cout << "Player has collided with a portal!" << std::endl;
         
    }

    std::cout << "Collision detected between entities: " << static_cast<uint32_t>(entityA)
              << " and " << static_cast<uint32_t>(entityB) << std::endl;
}


void ColliderRenderSystem::run(SDL_Renderer* renderer) {
    auto view = scene->r.view<TransformComponent, ColliderComponent, SpriteComponent>(); 

    for (auto entity : view) {
        auto [transform, collider, sprite] = view.get<TransformComponent, ColliderComponent, SpriteComponent>(entity);

         SDL_SetRenderDrawColor(renderer,
                               collider.isInCollision && !collider.isPortal ? 255 : 0, 
                               !collider.isInCollision && !collider.isPortal ? 255 : 0,
                               collider.isPortal ? 255 : 0, 
                               SDL_ALPHA_OPAQUE); 
        SDL_Rect rect = {
            static_cast<int>(transform.x ), 
            static_cast<int>(transform.y ), 
            static_cast<int>(collider.width ),  
            static_cast<int>(collider.height )  
        };

        SDL_RenderDrawRect(renderer, &rect);
        
        std::cout << "Entity: " << static_cast<uint32_t>(entity)
                  << " Collision: " << collider.isInCollision
                  << " Portal: " << collider.isPortal
                  << " Player: " << collider.isPlayer 
                  << " Enemy: " << collider.isEnemy << std::endl;
    }
}

void SceneTransitionSystem::run(double dT) {
    auto view = scene->r.view<ColliderComponent, TransformComponent>();

    for (auto entity : view) {
        auto& collider = view.get<ColliderComponent>(entity);

        if (collider.isInCollision) {
            if (collider.isPortal) {
                scene->~Scene();
                if (sceneManager.getCurrentSceneName() != "SCENE_2") {
                    sceneManager.switchToScene("SCENE_2");
                    setScene(sceneManager.getCurrentScene().get());

                }   
                collider.isInCollision = false;
            }

            // Si es un jugador y está en colisión, buscamos el portal
            if (collider.isPlayer) {
                for (auto otherEntity : view) {
                    if (entity == otherEntity) continue; // Nos saltamos la entidad actual

                    auto& otherCollider = view.get<ColliderComponent>(otherEntity);
                    if (otherCollider.isPortal && otherCollider.isInCollision) {
                        std::cout << "Player has collided with a portal!" << std::endl;
                        
                        scene->~Scene();
                            // sceneManager.getCurrentScene().~unique_ptr();
                        if (sceneManager.getCurrentSceneName() != "SCENE_2") {
                            sceneManager.switchToScene("SCENE_2");
                            setScene(sceneManager.getCurrentScene().get());

                        }
                        collider.isInCollision = false;
                        otherCollider.isInCollision = false;
                        break;
                    }
                }
            }
        }
    }
}

void HealthSystem::run(double dT){
    auto view = scene->r.view<ColliderComponent, Health_DamageComponent>();

    for (auto entity : view) {
        auto& collider = view.get<ColliderComponent>(entity);
        auto& healthBar = view.get<Health_DamageComponent>(entity);

        if (collider.isInCollision) {
            if(collider.isEnemy){
                healthBar.healthBar -= healthBar.damage;
                if(healthBar.healthBar <= 0){
                    print("HAS MUERTO!");
                    exit(0);
                }
            }

            std::cout << "Entity: " << static_cast<uint32_t>(entity)
                      << " Health: " << healthBar.healthBar << std::endl;
        }
    }
}