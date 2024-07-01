#pragma once
#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    explicit Map(int seed);

    void generate_map();
    void display_map();
    void set_coordinate_value(int y, int x, char value);

    [[nodiscard]] int get_size() const;
    [[nodiscard]] char get_coordinate_value(int y, int x) const;
    std::pair<int, int> get_destination();
private:
    int seed, destination_x, destination_y;
    std::vector<std::vector<char>> map;
};

#endif //MAP_H
