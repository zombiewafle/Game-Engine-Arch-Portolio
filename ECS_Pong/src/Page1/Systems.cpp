#include "print.h"
#include "Systems.h"
#include "Components.h"
#include <map> 
#include <sol/sol.hpp>
#include "Scripting/scriptManager.h"

std::map<SDL_Keycode, bool> keyState;
ScriptingManager scriptManager;  

void RectRenderSystem::run(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);

  const auto view = scene->r.view<TransformComponent, SizeComponent>();
  for (const entt::entity e : view) {
    const TransformComponent& t = view.get<TransformComponent>(e);
    const SizeComponent& c = view.get<SizeComponent>(e);
    const int x = t.position.x;
    const int y = t.position.y;
    const int w = c.w;
    const int h = c.h;

    SDL_Rect rect = { x, y, w, h };    
    SDL_RenderFillRect(renderer, &rect);
  }
}

MovementUpdateSystem::MovementUpdateSystem(int screen_width, int screen_height)
  : screen_width(screen_width), screen_height(screen_height) { }

void MovementUpdateSystem::run(double dT) {
  const auto view = scene->r.view<NameComponent, TransformComponent, SpeedComponent>();
  for (const entt::entity e : view) {
    TransformComponent& t = view.get<TransformComponent>(e);
    SpeedComponent& m = view.get<SpeedComponent>(e);
    NameComponent &name = view.get<NameComponent>(e);

    if (m.x == 0 && m.y == 0) {
      continue;
    }

  if (name.tag == "ball"){
    if (t.position.x <= 0)
    {
      m.x *= -1;
    }
    if (t.position.x >= screen_width - 20)
    {
      m.x *= -1;
    }
    if (t.position.y <= 0)
    {
      m.y *= -1;
    }
    if (t.position.y >= screen_height - 20)
    {
      print("Player 2 You lose.");
      exit(1);
    }

    else if(t.position.y <= 0){
      print("Player 1 You lose.");
      exit(1);
    }
  }
  
    t.position.x += m.x * dT;
    t.position.y += m.y * dT;
  }
}


void PlayerInputEventSystem::run(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        keyState[event.key.keysym.sym] = true;
    } else if (event.type == SDL_KEYUP) {
        keyState[event.key.keysym.sym] = false;
    }

    double ballPosY = 0.0;
    double paddlePosY = 0.0;

    scene->r.view<NameComponent, TransformComponent>().each(
        [&](const auto& entity, const NameComponent& name, const TransformComponent& transform) {
            if (name.tag == "ball") {
                ballPosY = static_cast<double>(transform.position.x);
            }
            if (name.tag == "paddle") {  
                paddlePosY = static_cast<double>(transform.position.x);
            }
        }
    );

    if (ballPosY == 0.0) {
        std::cerr << "Ball position not initialized!" << std::endl;
        return;  
    }

    scene->r.view<NameComponent, PlayerComponent, SpeedComponent, TransformComponent>().each(
        [&](const auto& entity, NameComponent & name, PlayerComponent& player, SpeedComponent& speed, TransformComponent& transform) {
            if (name.tag == "paddle") {  
                try {
                    sol::table paddleSpeedY = scriptManager.lua.create_table_with("value", 0.0);
                    sol::protected_function updateIA = scriptManager.lua["updateIA"];
                    
                    updateIA(ballPosY, paddlePosY, paddleSpeedY);

                    speed.x = paddleSpeedY["value"];

                } catch (const sol::error &e) {
                    std::cerr << "An exception occurred in Lua: " << e.what() << std::endl;
                }
            }
            else{
              if (keyState[SDLK_LEFT]) {
                    speed.x = -player.moveSpeed;
                } else if (keyState[SDLK_RIGHT]) {
                    speed.x = player.moveSpeed;
                } else {
                    speed.x = 0;
                }
              
            }
        }
    );
}


void CollisionDetectionUpdateSystem::run(double dT) {
    const auto view = scene->r.view<TransformComponent, SizeComponent, ColliderComponent>();
    const auto view2 = scene->r.view<TransformComponent, SizeComponent>();

    view.each([&](auto e1, TransformComponent& t1, SizeComponent& s1, ColliderComponent& c1) {
        SDL_Rect box1 = { t1.position.x, t1.position.y, s1.w, s1.h };

        view2.each([&](auto e2, TransformComponent& t2, SizeComponent& s2) {
            if (e1 == e2) return;

            SDL_Rect box2 = { t2.position.x, t2.position.y, s2.w, s2.h };

            if (SDL_HasIntersection(&box1, &box2)) {
              c1.triggered = true;
            }
        });
    });
}


void BounceUpdateSystem::run(double dT) {
    const auto view = scene->r.view<ColliderComponent, SpeedComponent>();

    view.each([&](auto e, ColliderComponent& c, SpeedComponent& s) {
      if (c.triggered) {
        c.triggered = false;
        s.y *= -1.1;
      }
    });
}