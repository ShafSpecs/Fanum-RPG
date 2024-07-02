#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include "../map/Map.h"
#include "../entities/Player.h"

class Display {
public:
    Display();

private:
    ftxui::ScreenInteractive screen;
};

#endif // DISPLAY_H
