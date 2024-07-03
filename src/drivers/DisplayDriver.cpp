#include "DisplayDriver.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

DisplayDriver::DisplayDriver(Displayable &displayable)
    : displayable_(displayable), screen_(ScreenInteractive::Fullscreen()) {}

void DisplayDriver::run()
{
  auto renderer = Renderer([&]
                           { return displayable_.render() | border; });

  screen_.Loop(renderer);
}
