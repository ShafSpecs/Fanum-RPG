#include "Display.h"
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Display::Display() :
    screen_(ScreenInteractive::TerminalOutput()) {
    // Initialize render_function_ with a default function
    render_function_ = []() {
        return vbox({
            text("Initializing...") | center
        });
    };

    main_component_ = Renderer([this] { return render_function_(); });
    std::thread([&] { screen_.Loop(main_component_); }).detach();
}

void Display::update(const std::string& content) {
    render_function_ = [content]() {
        return vbox({
            text(content) | center
        });
    };
    screen_.PostEvent(Event::Custom);
}
