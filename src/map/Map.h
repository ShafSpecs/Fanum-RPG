#pragma once
#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
public:
    explicit Map(int seed);

    [[nodiscard]] int get_size() const;

    bool is_within_bounds(int x, int y) const;
    void move_player(int x, int y);
    std::vector<std::vector<char>> get_map() const;
private:
    int seed_;
    std::vector<std::vector<char>> map_;
};

#endif //MAP_H
