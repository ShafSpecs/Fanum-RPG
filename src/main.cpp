#include <iostream>

#include "core/GameEngine.h"

int main() {
    GameEngine engine;
    engine.run();
    return 0;
}

// #include <ftxui/component/screen_interactive.hpp>
// #include <ftxui/dom/elements.hpp>
// #include <ftxui/component/component.hpp>
// #include <ftxui/component/component_base.hpp>
// #include <ftxui/component/event.hpp>
// #include <algorithm>
// #include <iostream>

// using namespace ftxui;
// using namespace std;

// class Game {
// public:
//     Game(int width, int height) : width(width), height(height), playerX(0), playerY(0) {}

//     void MovePlayer(int dx, int dy) {
//         playerX = std::clamp(playerX + dx, 0, width - 1);
//         playerY = std::clamp(playerY + dy, 0, height - 1);
//     }

//     Element Render() {
//         Elements board;
//         for (int y = 0; y < height; ++y) {
//             Elements row;
//             for (int x = 0; x < width; ++x) {
//                 if (x == playerX && y == playerY) {
//                     row.push_back(text("P") | bgcolor(Color::Red));
//                 } else {
//                     row.push_back(text("."));
//                 }
//             }
//             board.push_back(hbox(std::move(row)));
//         }
//         return vbox(std::move(board));
//     }

// private:
//     int width, height;
//     int playerX, playerY;
// };

// int main() {
//     auto screen = ScreenInteractive::Fullscreen();
//     Game game(10, 10);

//     auto renderer = Renderer([&] {
//         return game.Render() | border;
//     });

//     auto component = CatchEvent(renderer, [&](Event event) {
//         if (event == Event::ArrowUp) {
//             game.MovePlayer(0, -1);
//         } else if (event == Event::ArrowDown) {
//             game.MovePlayer(0, 1);
//         } else if (event == Event::ArrowLeft) {
//             game.MovePlayer(-1, 0);
//         } else if (event == Event::ArrowRight) {
//             game.MovePlayer(1, 0);
//         }
//         return true; // event handled
//     });

//     screen.Loop(component);

//     return 0;
// }
