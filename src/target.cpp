#include "target.h"
#include <cmath>
#include <iostream>

void Target::Update() {

    switch (direction) {
    case Direction::kUp:
      head_y -= speed_;
      break;

    case Direction::kDown:
      head_y += speed_;
      break;

    case Direction::kLeft:
      head_x -= speed_;
      break;

    case Direction::kRight:
      head_x += speed_;
      break;
  }

  // Wrap the Target around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);

  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.
}

// // Inefficient method to check if cell is occupied by Target.
bool Target::TargetCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  return false;
}