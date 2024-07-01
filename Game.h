#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Map.h"
#include "Player.h"


class Game {
public:
    Game();

    void play_turn();
    void display_map();
    [[nodiscard]] bool is_game_over();
private:
    static constexpr int MAP_SIZE = 10;
    Map map;
    Player player;

    [[nodiscard]] bool is_move_valid(char direction) const;
};

#endif //GAME_H
