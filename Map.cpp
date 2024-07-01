#include "Map.h"

#include <iostream>

Map::Map(int seed):
    seed(seed),
    destination_x(seed - 1),
    destination_y(seed - 1),
    map(seed, std::vector<char>(seed, '.'))
{
    if (seed <= 0) {
        std::cout << "Seed cannot be 0. Using default seed 10.\n";
        seed = 10;
    }
}

void Map::generate_map() {
    for (int y = 0; y < seed; ++y) {
        for (int x = 0; x < seed; ++x) {
            map[y][x] = '.';
        }
    }
}

int Map::get_size() const {
    return seed;
}

void Map::display_map() {
    for (const auto& row : map) {
        for (const char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}

void Map::set_coordinate_value(const int y, const int x, const char value) {
    map[y][x] = value;
}

char Map::get_coordinate_value(const int y, const int x) const {
    return map[y][x];
}

std::pair<int, int> Map::get_destination() {
    return {destination_y, destination_x};
}

