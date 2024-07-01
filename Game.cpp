#include <iostream>

#include "Game.h"

Game::Game():
    map(Map(MAP_SIZE)),
    player(0, 0, 3)
{
    map.generate_map();
    map.set_coordinate_value(0, 0, 'P');
    auto [y, x] = map.get_destination();
    map.set_coordinate_value(y, x, 'B');
}

void Game::play() {
    while(!is_game_over()) {
        play_turn();
    }
}


void Game::play_turn() {
    display_map();
    std::cout << "Enter move (n/s/e/w): ";
    char move;
    std::cin >> move;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (!is_move_valid(move)) {
        std::cout << "Invalid move. Try again.\n";
        return;
    }

    if (player.x == 0 && player.y == 0)
        map.set_coordinate_value(player.y, player.x, 'A');
    else
        map.set_coordinate_value(player.y, player.x, '.');

    player.move(move);
    map.set_coordinate_value(player.y, player.x, 'P');

    const auto [y, x] = map.get_destination();

    if (player.y == y && player.x == x) {
        std::cout << "Congratulations! You've reached the destination.\n";
    } else if (player.moves_left == 0) {
        player.moves_left = 3; // Reset moves for next turn
        std::cout << "Turn ended. Moves reset.\n";
    }
}

void Game::display_map() {
    map.display_map();
}


bool Game::is_game_over() {
    auto [y, x] = map.get_destination();
    return (player.x == x && player.y == y);
}

bool Game::is_move_valid(const char direction) const {
    int x = player.x, y = player.y;

    switch (direction) {
        case 'n': y--; break;
        case 's': y++; break;
        case 'w': x--; break;
        case 'e': x++; break;
        default: return false;
    }

    return x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE;
}
