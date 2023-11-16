#include "print.h"
#include "Page1.h"
#include "Systems.h"
#include "Components.h"
#include "ECS/Entity.h"

Page1::Page1() : Game("Page1", SCREEN_WIDTH, SCREEN_HEIGHT) {
    std::unique_ptr<Scene> gameplayScene = createGameplayScene();
    setScene(std::move(gameplayScene));
}

Page1::~Page1() {
    // destructor implementation
}

std::unique_ptr<Scene> Page1::createGameplayScene()
{
    // Create a unique_ptr to hold the created scene
    std::unique_ptr<Scene> gameplayScene = std::make_unique<Scene>("Gameplay");

    Entity ball = gameplayScene->createEntity("ball", 100, 100);
    ball.addComponent<SpeedComponent>(200, 200);
    ball.addComponent<SizeComponent>(30, 30);
    ball.addComponent<ColliderComponent>(false);

    Entity paddle = gameplayScene->createEntity("paddle", (screen_width/2)-50, screen_height-20);
    paddle.addComponent<SpeedComponent>(0, 0);
    paddle.addComponent<SizeComponent>(100, 20);
    paddle.addComponent<PlayerComponent>(200);
    
    Entity paddle2 = gameplayScene->createEntity("paddle2", (screen_width/2)-50, 20); // 20 para que esté cerca del borde superior
    paddle2.addComponent<SpeedComponent>(0, 0);    // Velocidad inicial
    paddle2.addComponent<SizeComponent>(100, 20);  // Tamaño del paddle
    paddle2.addComponent<PlayerComponent>(200);    // Velocidad de movimiento cuando el jugador lo controla


    // gameplayScene->addSetupSystem<HelloSystem>();
    gameplayScene->addRenderSystem<RectRenderSystem>();
    gameplayScene->addUpdateSystem<MovementUpdateSystem>(SCREEN_WIDTH, SCREEN_HEIGHT);
    gameplayScene->addEventSystem<PlayerInputEventSystem>();
    gameplayScene->addUpdateSystem<CollisionDetectionUpdateSystem>();
    gameplayScene->addUpdateSystem<BounceUpdateSystem>();

    return gameplayScene;
}

