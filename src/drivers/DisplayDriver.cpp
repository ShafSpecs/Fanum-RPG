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

  auto component = CatchEvent(renderer, [&](Event event)
                              { return displayable_.handle_event(event); });

  screen_.Loop(component);
}
