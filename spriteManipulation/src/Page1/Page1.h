#pragma once
#include "Game/Game.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Page1 : public Game {
  public:
    Page1();
    ~Page1();

  private:
    std::unique_ptr<Scene> createGameplayScene();
};
