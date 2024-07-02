#include "Display.h"
#include <ftxui/dom/elements.hpp>

using namespace ftxui;

Display::Display():
    screen(ScreenInteractive::TerminalOutput())
{
}
