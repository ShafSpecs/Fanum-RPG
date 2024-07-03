#pragma once
#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <ftxui/component/screen_interactive.hpp>
#include "../core/Displayable.h"

class DisplayDriver {
public:
    DisplayDriver(Displayable& displayable);

    void run();

private:
    Displayable& displayable_;
    ftxui::ScreenInteractive screen_;
};

#endif // DISPLAY_DRIVER_H
