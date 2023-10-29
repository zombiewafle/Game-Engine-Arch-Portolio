#pragma once
#include "Game/Game.h"


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class spManipulation : public Game {
  public:
    spManipulation();
    ~spManipulation();

  private:
    std::unique_ptr<Scene> createGameplayScene();
};
