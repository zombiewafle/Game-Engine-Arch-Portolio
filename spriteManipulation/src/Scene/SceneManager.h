#pragma once

#include <memory>
#include <unordered_map>
#include <string>
#include "Scene.h"
#include <SDL.h>
#include "Game/Game.h" 

class SceneManager {
private:
    std::unordered_map<std::string, std::unique_ptr<Scene>> scenes;
    std::unique_ptr<Scene> currentScene;
    std::string currentSceneName;
    // Game* game;


public:
    SceneManager();
    void teardown();
    void addScene(const std::string& name, std::unique_ptr<Scene> scene);
    void switchToScene(const std::string& name);
    void updateCurrentScene(double dT);
    void renderCurrentScene(SDL_Renderer* renderer);
    void handleEventCurrentScene(SDL_Event& event);
    Scene* getCurrentScene() const; 
    std::unique_ptr<Scene>& getCurrentScene();
    bool hasScene(const std::string& name) const; 
    const std::string& getCurrentSceneName() const;

    bool isTransition;
};
