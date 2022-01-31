#include "target.h"
#include <cmath>
#include <iostream>

void Target::Update() {

    switch (direction_) {
    case Direction::kUp:
      head_y_ -= speed_;
      break;

    case Direction::kDown:
      head_y_ += speed_;
      break;

    case Direction::kLeft:
      head_x_ -= speed_;
      break;

    case Direction::kRight:
      head_x_ += speed_;
      break;
  }

  // Wrap the Target around to the beginning if going off of the screen.
  head_x_ = fmod(head_x_ + grid_width_, grid_width_);
  head_y_ = fmod(head_y_ + grid_height_, grid_height_);

  SDL_Point current_cell{
      static_cast<int>(head_x_),
      static_cast<int>(head_y_)};  // Capture the head's cell after updating.
}

// // Inefficient method to check if cell is occupied by Target.
bool Target::TargetCell(int x, int y) {
  if (x == static_cast<int>(head_x_) && y == static_cast<int>(head_y_)) {
    return true;
  }
  return false;
}