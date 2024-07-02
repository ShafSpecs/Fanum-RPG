#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "Map.h"
#include "Player.h"

class Display {
public:
    Display();
    void update(const std::string& content);

private:
    ftxui::ScreenInteractive screen_;
    ftxui::Component main_component_;
    std::function<ftxui::Element()> render_function_;
};

#endif // DISPLAY_H
