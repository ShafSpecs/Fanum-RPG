#include "Map.h"

#include <iostream>

Map::Map(const int seed):
    seed_(seed),
    map_(seed, std::vector<char>(seed, '.'))
{
    if (seed_ <= 0) {
        std::cout << "Seed cannot be 0. Using default seed 10.\n";
        seed_ = 10;
    }
}

int Map::get_size() const {
    return seed_;
}

std::vector<std::vector<char>> Map::get_map() const {
    return map_;
}

bool Map::is_within_bounds(int x, int y) const {
    return x >= 0 && x < seed_ && y >= 0 && y < seed_;
}

void Map::move_player(int x, int y) {
  if (is_within_bounds(x, y)) {
    map_[y][x] = 'P';
  }
}
