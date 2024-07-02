#include "display.h"
#include <iostream>

Display::Display() : hConsole(GetStdHandle(STD_OUTPUT_HANDLE)) {}

void Display::init()
{
  // Get the console handle and clear the screen
  clearScreen();

  // Hide the cursor
  CONSOLE_CURSOR_INFO cursorInfo;
  GetConsoleCursorInfo(hConsole, &cursorInfo);
  cursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(hConsole, &cursorInfo);

  getConsoleSize();
}

void Display::clearScreen()
{
  // Get the console screen buffer info
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);

  // Calculate the number of cells in the current buffer
  DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;

  // Fill the entire buffer with spaces
  DWORD count;
  FillConsoleOutputCharacter(hConsole, TEXT(' '), cellCount, {0, 0}, &count);

  // Fill the entire buffer with the current colors and attributes
  FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, {0, 0}, &count);

  // Move the cursor to the top-left corner
  SetConsoleCursorPosition(hConsole, {0, 0});
}

void Display::moveCursor(SHORT x, SHORT y)
{
  SetConsoleCursorPosition(hConsole, {x, y});
}

void Display::getConsoleSize()
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  bufferSize.X = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  bufferSize.Y = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void Display::update(const Map &map, int player_x, int player_y)
{
  clearScreen();

  std::vector<std::string> buffer(map.get_size());
  for (int y = 0; y < map.get_size(); ++y)
  {
    for (int x = 0; x < map.get_size(); ++x)
    {
      if (x == player_x && y == player_y)
      {
        buffer[y] += '@';
      }
      else
      {
        buffer[y] += map.get_coordinate_value(y, x);
      }
    }
  }

  clearScreen();
  for (int y = 0; y < map.get_size(); ++y)
  {
    moveCursor(0, static_cast<SHORT>(y));
    std::cout << buffer[y];
  }
  std::cout.flush();
}

void Display::print(const std::string &message)
{
  // Print message at a specific location, e.g., below the map
  moveCursor(0, static_cast<SHORT>(bufferSize.Y - 1));
  std::cout << message;
}