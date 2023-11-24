#include <string>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include "print.h"

#include "Scene.h"
#include "ECS/Entity.h"
#include "ECS/Components.h"
#include "ECS/System.h"


Scene::Scene(const std::string& name)
  : name(name)
{
  print("Scene ", name, "constructed!");
  world = new Entity(r.create(), this);
  world->addComponent<TilemapComponent>();
  // world->addComponent<ColliderComponent>(x, y);

  player = new Entity(r.create(), this);
  player->addComponent<TransformComponent>(0, 0);
  player->addComponent<SpeedComponent>(0, 0);
  player->addComponent<RigidbodyComponent>(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), true, 1.0f, false); 
  player->addComponent<ColliderComponent>(16,16);
}

Scene::~Scene()
{
  print("Scene Destroyed!");
}

Entity Scene::createEntity(const std::string& name, int x, int y)
{
  Entity entity = { r.create(), this };
  entity.addComponent<NameComponent>(name);
  entity.addComponent<TransformComponent>(x, y);
  entity.addComponent<RigidbodyComponent>(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), true, 1.0f, false); 
  entity.addComponent<ColliderComponent>(16,16);
  // entity.addComponent<RigidbodyComponent>(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), true, 1.0f, true); 

  return entity;
}

void Scene::setup()
{
  print("Scene Setup");
  
  for (auto sys: setupSystems)
  {
    sys->run();
  }
}

void Scene::update(double dT)
{
  print("Scene Update");
  
  for (auto sys: updateSystems)
  {
    sys->run(dT);
  }
}

void Scene::render(SDL_Renderer* renderer)
{
  print("Scene Render");
  
  for (auto sys: renderSystems)
  {
    sys->run(renderer);
  }
}

void Scene::processEvents(SDL_Event event)
{
  print("Scene Events");
  
  for (auto sys: eventSystems)
  {
    sys->run(event);
  }
}