#pragma once
#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <ftxui/dom/elements.hpp>
#include <ftxui/component/event.hpp>

class Displayable {
  public:
    virtual ~Displayable() = default;
    virtual ftxui::Element render() = 0;
    virtual bool handle_event(ftxui::Event event) = 0;
};

#endif //DISPLAYABLE_H
