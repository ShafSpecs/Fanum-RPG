#pragma once
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Game.h"
#include "../drivers/DisplayDriver.h"

class GameEngine {
public:
    GameEngine();
    void run();

private:
    Game game_;
    DisplayDriver display_driver_;
    Displayable* current_displayable_;
};

#endif // GAME_ENGINE_H
