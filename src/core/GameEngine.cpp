#include "GameEngine.h"

GameEngine::GameEngine():
  game_(Game()),
  display_driver_(DisplayDriver(game_)),
  current_displayable_(&game_)
{

}

void GameEngine::run()
{
  display_driver_.run();
}