#pragma once
#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include <ftxui/dom/elements.hpp>

class Displayable {
  public:
    virtual ~Displayable() = default;
    virtual ftxui::Element render() = 0;
};

#endif //DISPLAYABLE_H
