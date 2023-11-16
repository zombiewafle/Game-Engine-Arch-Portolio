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

  Entity red = scene->createEntity("player", 0, 0);
  auto& s = red.addComponent<SpriteComponent>(
    "Sprites/Player/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000,
    Shaders::red,
    SDL_GetTicks()
  );
  
  s.lastUpdate = SDL_GetTicks();

  Entity black = scene->createEntity("enemy", 20, 0);
  black.addComponent<SpriteComponent>(
    "Sprites/Player/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000,
    Shaders::grayscale, 
    SDL_GetTicks()
  );

  Entity shadow = scene->createEntity("enemy", 40, 0);
  shadow.addComponent<SpriteComponent>(
    "Sprites/Player/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000,
    Shaders::shadow, 
    SDL_GetTicks()
  );

  
  Entity vanilla = scene->createEntity("enemy", 60, 0);
  vanilla.addComponent<SpriteComponent>(
    "Sprites/Player/SpriteSheet.png",
    0, 0,
    48,
    8,
    1000
  ); 
  
  scene->addSetupSystem<TilemapSetupSystem>(renderer);
  scene->addRenderSystem<TilemapRenderSystem>();

  scene->addSetupSystem<SpriteSetupSystem>(renderer);
  scene->addRenderSystem<SpriteRenderSystem>();
  scene->addUpdateSystem<SpriteUpdateSystem>();

  return scene; 
}
