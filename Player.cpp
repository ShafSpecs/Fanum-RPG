#include "Player.h"

Player::Player(const int start_x, const int start_y, const int max_moves):
    x(start_x), y(start_y), moves_left(max_moves)
{
    if (x < 0 || y < 0) {
        // Ensure player starts within the map
        x = 0;
        y = 0;
    }
}

void Player::move(const char direction) {
    switch (direction) {
        case 'n': y--; break;
        case 's': y++; break;
        case 'w': x--; break;
        case 'e': x++; break;
        default: break;
    }

    moves_left--;
}
