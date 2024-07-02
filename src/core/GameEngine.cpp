#include "GameEngine.h"

GameEngine::GameEngine() : game_(Game())
{
}

void GameEngine::run()
{
  game_.play();
}