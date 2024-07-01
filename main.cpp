#include <iostream>

#include "Game.h"

int main() {
    Game game;

    while (!game.is_game_over()) {
        game.display_map();
        game.play_turn();
    }

    return 0;
}