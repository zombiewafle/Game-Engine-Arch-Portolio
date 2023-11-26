#include "SceneManager.h"
#include "Game/Game.h"
#include <iostream> 


SceneManager::SceneManager() = default;

void SceneManager::addScene(const std::string& name, std::unique_ptr<Scene> scene) {
    scenes[name] = std::move(scene);
}

void SceneManager::switchToScene(const std::string& name) {
    auto it = scenes.find(name);
    if (it != scenes.end()) {
        // Liberar la escena actual automáticamente al reasignar el unique_ptr
        currentScene = std::move(it->second);
        // La escena antigua se destruye aquí, ya que el unique_ptr que la sostenía ha sido movido

        // Configura la nueva escena actual
        currentSceneName = name;
        currentScene->setup();
        isTransition = true;
    } else {
        // Manejar el caso en que la escena no exista
        std::cerr << "Scene '" << name << "' not found." << std::endl;
    }
}



void SceneManager::updateCurrentScene(double dT) {
    if (currentScene) {
        currentScene->update(dT);
    }
}

void SceneManager::renderCurrentScene(SDL_Renderer* renderer) {
    if (currentScene) {
        currentScene->render(renderer);
    }
}

void SceneManager::handleEventCurrentScene(SDL_Event& event) {
    if (currentScene) {
        currentScene->processEvents(event);
    }
}

Scene* SceneManager::getCurrentScene() const {
    return currentScene.get(); 
}

std::unique_ptr<Scene>& SceneManager::getCurrentScene() {
    return currentScene;
}

bool SceneManager::hasScene(const std::string& name) const { 
    return scenes.find(name) != scenes.end();
}

const std::string& SceneManager::getCurrentSceneName() const {
    return currentSceneName;
}