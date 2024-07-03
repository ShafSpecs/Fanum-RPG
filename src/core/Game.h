#pragma once
#ifndef GAME_H
#define GAME_H

#include "Displayable.h"
#include "../entities/Player.h"
#include "../map/Map.h"

class Game : public Displayable {
public:
    Game();

    void play();

    [[nodiscard]] bool is_game_over();
    void move_player(int dx, int dy);

    ftxui::Element render() override;
private:
    static constexpr int MAP_SIZE = 10;
    static constexpr int MOVES_PER_TURN = 3;
    Map map_;
    Player player_;
    int moves_left_;

    void play_turn();
    [[nodiscard]] bool is_move_valid(int x, int y) const;
};

#endif //GAME_H
