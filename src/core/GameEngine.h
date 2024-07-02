#pragma once
#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Game.h"

class GameEngine {
public:
    GameEngine();
    void run();

private:
    Game game_;
};

#endif // GAME_ENGINE_H
