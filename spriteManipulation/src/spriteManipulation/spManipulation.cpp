#include <print.h>
#include "spManipulation.h"
#include "Systems.h"
#include "Components.h"
#include "ECS/Entity.h"
#include "Shaders.h"

spManipulation::spManipulation() : Game("spManipulation", SCREEN_WIDTH, SCREEN_HEIGHT) {
    timer++;


    if(timer == 5){
        print("HOLA");
    }
    
    setupInitialScene();
}

spManipulation::~spManipulation() {}

void spManipulation::setupInitialScene() {
    auto initialScene = createGameplayScene();
    sceneManager.addScene("SCENE_1", std::move(initialScene));
    

    auto secondScene = createAnotherScene(); 
    sceneManager.addScene("SCENE_2", std::move(secondScene));

    sceneManager.switchToScene("SCENE_1");
    
    setScene(std::move(sceneManager.getCurrentScene()));

      // scene->addUpdateSystem<PhysicsSystem>();



}

std::unique_ptr<Scene> spManipulation::createGameplayScene() {
    auto scene = std::make_unique<Scene>("SCENE_1");


    Entity black = scene->createEntity("enemy", 20, 0);
    black.addComponent<SpriteComponent>(
        "Sprites/Player/SpriteSheet.png",
        0, 0,
        48,
        8,
        1000,
        Shaders::grayscale, 
        SDL_GetTicks()
        // 0,0,0,0
    );

        scene->portal->addComponent<SpriteComponent>(
        "Tiles/portal.png",
        0, 0,
        48,
        1,
        1000,
        PixelShader{nullptr, ""},
        SDL_GetTicks()
        // 0,0,0,0
    );

    scene->player->addComponent<SpriteComponent>(
        "Sprites/Player/Sprite-0001.png",
        0, 0,
        48,
        4,
        1000,
        PixelShader{nullptr, ""},
        SDL_GetTicks()
        // 0,0,0,0
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
    scene->addUpdateSystem<HealthSystem>();
    // scene->addUpdateSystem<SceneTransitionSystem>(std::ref(sceneManager));

    

    // scene->addUpdateSystem<PhysicsSystem>();
    scene->addUpdateSystem<CollisionSystem>();

    return scene; 
}

std::unique_ptr<Scene> spManipulation::createAnotherScene() {
    auto scene = std::make_unique<Scene>("SCENE_2");

    // Entity black = scene->createEntity("enemy", 20, 0);
    // black.addComponent<SpriteComponent>(
    //     "Sprites/Player/SpriteSheet.png",
    //     0, 0,
    //     48,
    //     8,
    //     1000,
    //     Shaders::grayscale, 
    //     SDL_GetTicks()
    //     // 0,0,0,0
    // );

    scene->portal->addComponent<SpriteComponent>(
      "Tiles/portal.png",
      90, 90,
      48,
      1,
      1000,
      PixelShader{nullptr, ""},
      SDL_GetTicks()
      // 0,0,0,0
    );

    scene->player->addComponent<SpriteComponent>(
      "Sprites/Player/Sprite-0001.png",
      0, 0,
      48,
      4,
      1000,
      PixelShader{nullptr, ""},
      SDL_GetTicks()
      // 0,0,0,0
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
    scene->addUpdateSystem<HealthSystem>();
    // scene->addUpdateSystem<SceneTransitionSystem>(std::ref(sceneManager));
    
    scene->addUpdateSystem<CollisionSystem>();

    return scene; 
}
