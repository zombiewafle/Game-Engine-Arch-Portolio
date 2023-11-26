#include "print.h"
#include "Page1.h"
#include "Systems.h"
#include "Components.h"
#include "ECS/Entity.h"
#include "Scripting/scriptManager.h"

Page1::Page1() : Game("Page1", SCREEN_WIDTH, SCREEN_HEIGHT) {
    ScriptingManager::setup();
    ScriptingManager::runFile("scripts/ia.lua");

    std::unique_ptr<Scene> gameplayScene = createGameplayScene();
    setScene(std::move(gameplayScene));
}

Page1::~Page1() {}

std::unique_ptr<Scene> Page1::createGameplayScene()
{
    std::unique_ptr<Scene> gameplayScene = std::make_unique<Scene>("Gameplay");

    Entity ball = gameplayScene->createEntity("ball", 100, 100);
    ball.addComponent<SpeedComponent>(200, 200);
    ball.addComponent<SizeComponent>(30, 30);
    ball.addComponent<ColliderComponent>(false);

    Entity paddle = gameplayScene->createEntity("paddlePlayer", (screen_width/2)-50, screen_height-20);
    paddle.addComponent<SpeedComponent>(0, 0);
    paddle.addComponent<SizeComponent>(100, 20);
    paddle.addComponent<PlayerComponent>(200);
    
    Entity paddle2 = gameplayScene->createEntity("paddle", (screen_width/2)-50, 20); 
    paddle2.addComponent<SpeedComponent>(0, 0);    
    paddle2.addComponent<SizeComponent>(100, 20);  
    paddle2.addComponent<PlayerComponent>(200);    


    gameplayScene->addRenderSystem<RectRenderSystem>();
    gameplayScene->addUpdateSystem<MovementUpdateSystem>(SCREEN_WIDTH, SCREEN_HEIGHT);
    gameplayScene->addEventSystem<PlayerInputEventSystem>();
    gameplayScene->addUpdateSystem<CollisionDetectionUpdateSystem>();
    gameplayScene->addUpdateSystem<BounceUpdateSystem>();

    return gameplayScene;
}

