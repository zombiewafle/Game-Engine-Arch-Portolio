#pragma once

#include <iostream>
#include "ECS/System.h"
#include <FastNoise.h>

class RectRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};

class MovementUpdateSystem : public UpdateSystem {
  public:
    MovementUpdateSystem(int screen_width, int screen_height);

    void run(double dT) override;

  private:
    int screen_width;
    int screen_height;
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
    FastNoiseLite noise; // Asumimos que tienes una instancia de ruido aquí.
    float offsetX;
    float offsetY;
    float zoom;

    // Método auxiliar para determinar si un tile es parte de la mazmorra.
    bool isDungeonTile(int x, int y) {
        // El ruido nos da un valor entre -1 y 1.
        float noiseValue = noise.GetNoise(
            static_cast<float>(x + offsetX) * zoom, 
            static_cast<float>(y + offsetY) * zoom
        );

        // Utilizamos un umbral para determinar si es un espacio abierto.
        return noiseValue > -0.2f && noiseValue < 0.2f;
    }
};

class TilemapRenderSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override;
};
