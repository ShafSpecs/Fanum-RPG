#include <algorithm>
#include <iostream>
#include <ftxui/dom/elements.hpp>

#include "Game.h"

using namespace ftxui;

Game::Game() : map_(Map(MAP_SIZE)),
               player_(0, 0),
               moves_left_(MOVES_PER_TURN)
{
}

void Game::play()
{
  while (!is_game_over())
  {
    play_turn();
  }
}

void Game::play_turn()
{
  // ...
}

bool Game::is_game_over()
{
  // auto [y, x] = map_.get_destination();
  // return (player_.x == x && player_.y == y);
  return false;
}

bool Game::is_move_valid(int x, int y) const
{
  return map_.is_within_bounds(x, y);
}

Element Game::render() {
    map_ = Map(MAP_SIZE); // Reset map
    map_.move_player(player_.x, player_.y);

    Elements board;
    auto map_grid = map_.get_map();
    for (int y = 0; y < MAP_SIZE; ++y) {
        Elements row;
        for (int x = 0; x < MAP_SIZE; ++x) {
            if (map_grid[y][x] == 'P') {
                row.push_back(text("P") | bgcolor(Color::Red));
            } else {
                row.push_back(text("."));
            }
        }
        board.push_back(hbox(std::move(row)));
    }
    return vbox(std::move(board));
}

void Game::move_player(int dx, int dy) {
  int new_x = std::clamp(player_.x + dx, 0, MAP_SIZE - 1);
    int new_y = std::clamp(player_.y + dy, 0, MAP_SIZE - 1);
    if (is_move_valid(new_x, new_y) && moves_left_ > 0) {
        player_.x = new_x;
        player_.y = new_y;
        moves_left_--;
    }
    if (moves_left_ == 0) {
        moves_left_ = MOVES_PER_TURN;
    }
}

bool Game::handle_event(Event event) {
    if (event == Event::ArrowUp) {
        move_player(0, -1);
        return true;
    } else if (event == Event::ArrowDown) {
        move_player(0, 1);
        return true;
    } else if (event == Event::ArrowLeft) {
        move_player(-1, 0);
        return true;
    } else if (event == Event::ArrowRight) {
        move_player(1, 0);
        return true;
    }
    return false;
}
