#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include <Windows.h>
#include <string>
#include "map.h"

class Display {
public:
    Display();
    void init();
    void update(const Map& map, int player_x, int player_y);
    void moveCursor(SHORT x, SHORT y);
    void clearScreen();
    void print(const std::string& message);

private:
    HANDLE hConsole;
    COORD bufferSize;
    void getConsoleSize();
};

#endif //DISPLAY_H
