#include <print.h>
#include "spManipulation.h"
#include "Systems.h"
#include "Components.h"
#include "ECS/Entity.h"
#include "Shaders.h"

spManipulation::spManipulation() : Game("spManipulation", SCREEN_WIDTH, SCREEN_HEIGHT) {
  auto gameplayScene = createGameplayScene();
  setScene(std::move(gameplayScene));
}

spManipulation::~spManipulation() {
}

std::unique_ptr<Scene> spManipulation::createGameplayScene()
{
  auto scene = std::make_unique<Scene>("GAMEPLAY SCENE");

  Entity black = scene->createEntity("enemy", 20, 0);
  black.addComponent<SpriteComponent>(
    "Sprites/Player/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000,
    Shaders::grayscale, 
    SDL_GetTicks(),
    0,0,0,0
  );

  scene->player->addComponent<SpriteComponent>(
    "Sprites/Player/Sprite-0001.png",
    0, 0,
    48,
    4,
    1000,
    PixelShader{nullptr, ""},
    SDL_GetTicks(),
    0,0,0,0
  );


  scene->addSetupSystem<TilemapSetupSystem>(renderer);
  scene->addRenderSystem<TilemapRenderSystem>();

  scene->addEventSystem<PlayerInputEventSystem>();
  scene->addUpdateSystem<PlayerSpriteUpdateSystem>();
  scene->addUpdateSystem<MovementUpdateSystem>();

  scene->addSetupSystem<SpriteSetupSystem>(renderer);
  scene->addRenderSystem<SpriteRenderSystem>();
  scene->addUpdateSystem<SpriteUpdateSystem>();
  scene->addRenderSystem<ColliderRenderSystem>();
  

  // scene->addUpdateSystem<PhysicsSystem>();
  scene->addUpdateSystem<CollisionSystem>();

  return scene; 
}
