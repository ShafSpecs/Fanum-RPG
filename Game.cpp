#include <iostream>

#include "Game.h"

Game::Game(): map(MAP_SIZE, std::vector<char>(MAP_SIZE, '.')),
              player(0, 0, 3),
              destination_x(MAP_SIZE - 1),
              destination_y(MAP_SIZE - 1) {
    map[0][0] = 'P';
    map[destination_y][destination_x] = 'B';
}

void Game::play_turn() {
    char move;
    std::cout << "Enter move (n/s/e/w): ";
    std::cin >> move;

    if (move != 'n' && move != 's' && move != 'e' && move != 'w') {
        std::cout << "Invalid move. Try again.\n";
        return;
    }

    map[player.y][player.x] = '.';
    player.move(move);
    map[player.y][player.x] = 'P';

    if (player.x == destination_x && player.y == destination_y) {
        std::cout << "Congratulations! You've reached the destination.\n";
    } else if (player.moves_left == 0) {
        player.moves_left = 3; // Reset moves for next turn
        std::cout << "Turn ended. Moves reset.\n";
    }
}


void Game::display_map() {
    for (const auto &row: map) {
        for (const char cell: row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Moves left: " << player.moves_left << '\n';
}

bool Game::is_game_over() const {
    return (player.x == destination_x && player.y == destination_y);
}
