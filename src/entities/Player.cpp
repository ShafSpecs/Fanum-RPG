#include "Player.h"

Player::Player(const int start_x, const int start_y):
    x(start_x), y(start_y)
{
    if (x < 0 || y < 0) {
        // Ensure player starts within the map
        x = 0;
        y = 0;
    }
}
