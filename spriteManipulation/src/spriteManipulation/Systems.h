#pragma once

#include <iostream>
#include "ECS/System.h"
#include "ECS/Components.h"
#include <FastNoise.h>

class RectRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};

class MovementUpdateSystem : public UpdateSystem {
  public:
    void run(double dT) override;
};

class PlayerInputEventSystem : public EventSystem {
  public:
    void run(SDL_Event event) override;
};

class CollisionDetectionUpdateSystem : public UpdateSystem {
  public:
    void run(double dT) override;
};

class BounceUpdateSystem : public UpdateSystem {
  public:
    void run(double dT) override;
};

class SpriteSetupSystem : public SetupSystem {
  public:
    SpriteSetupSystem(SDL_Renderer* renderer);
    ~SpriteSetupSystem();

    void run() override;

  private:
    SDL_Renderer* renderer;
};

class SpriteUpdateSystem : public UpdateSystem {
  public:
    void run(double dT) override;
};

class SpriteRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};

class TilemapSetupSystem : public SetupSystem {
public:
    TilemapSetupSystem(SDL_Renderer* renderer);
    ~TilemapSetupSystem();
    void run() override;

private:
    SDL_Renderer* renderer;
    FastNoiseLite noise; 
    float offsetX;
    float offsetY;
    float zoom;

    bool isDungeonTile(int x, int y) {
        float noiseValue = noise.GetNoise(
            static_cast<float>(x + offsetX) * zoom, 
            static_cast<float>(y + offsetY) * zoom
        );

        return noiseValue > -0.2f && noiseValue < 0.2f;
    }
};

class TilemapRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};

class PlayerSpriteUpdateSystem : public UpdateSystem {
  public:
    void run(double dT) override;
};

// const glm::vec2 GRAVITY(0.0f, -9.81f); // Definir la gravedad

class PhysicsSystem : public UpdateSystem {
public:
    void run(double dT) override;
};


class ColliderRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};

class CollisionSystem : public UpdateSystem {
public:
  void run(double dT) override;

private:
  bool checkAABBCollision(TransformComponent& transformA, ColliderComponent& colliderA,
                          TransformComponent& transformB, ColliderComponent& colliderB);
  void handleCollision(entt::entity entityA, entt::entity entityB);
};



