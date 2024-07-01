#ifndef GAME_H
#define GAME_H

#include <vector>

#include "Player.h"


class Game {
public:
    Game();

    void display_map();
    void play_turn();
    [[nodiscard]] bool is_game_over() const;
private:
    static constexpr int MAP_SIZE = 10;
    std::vector<std::vector<char>> map;
    Player player;
    int destination_x, destination_y;
};



#endif //GAME_H
