#include <memory>
#include <unordered_map>
#include "Scene.h"

class SceneManager {
private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;

public:
    SceneManager() = default;

    void addScene(const std::string& name, std::shared_ptr<Scene> scene) {
        scenes[name] = scene;
    }

    void switchToScene(const std::string& name) {
        auto it = scenes.find(name);
        if (it != scenes.end()) {
            if (currentScene) {
                // Puedes llamar a un método de 'teardown' si es necesario.
                // currentScene->teardown();
            }
            currentScene = it->second;
            currentScene->setup();  // Configura la nueva escena.
        }
    }

    void updateCurrentScene(double dT) {
        if (currentScene) {
            currentScene->update(dT);
        }
    }

    void renderCurrentScene(SDL_Renderer* renderer) {
        if (currentScene) {
            currentScene->render(renderer);
        }
    }

    void handleEventCurrentScene(SDL_Event event) {
        if (currentScene) {
            currentScene->processEvents(event);
        }
    }

    std::shared_ptr<Scene> getCurrentScene() const {
        return currentScene;
    }
};
