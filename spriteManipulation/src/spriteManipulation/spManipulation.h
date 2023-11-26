#pragma once
#include "Game/Game.h"
#include "Scene/SceneManager.h" 

//Screen dimension constants
const int SCREEN_WIDTH = 897;
const int SCREEN_HEIGHT = 670;

class spManipulation : public Game {
public:
    spManipulation();
    ~spManipulation();

    void setupInitialScene();
    float timer = 0.0;

private:
    std::unique_ptr<Scene> createGameplayScene();
    std::unique_ptr<Scene> createAnotherScene(); 
    SceneManager sceneManager;
};

