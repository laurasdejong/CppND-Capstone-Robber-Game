#include "target.h"
#include <cmath>
#include <iostream>

void Target::Update() {

    switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Target around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);

  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the Target head has moved to a new
  // cell.
  // if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
  //   UpdateBody(current_cell, prev_cell);
  // }
}

// void Target::UpdateHead() {
//   switch (direction) {
//     case Direction::kUp:
//       head_y -= speed;
//       break;

//     case Direction::kDown:
//       head_y += speed;
//       break;

//     case Direction::kLeft:
//       head_x -= speed;
//       break;

//     case Direction::kRight:
//       head_x += speed;
//       break;
//   }

//   // Wrap the Target around to the beginning if going off of the screen.
//   head_x = fmod(head_x + grid_width, grid_width);
//   head_y = fmod(head_y + grid_height, grid_height);
// }

// void Target::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
//   // Add previous head location to vector
//   body.push_back(prev_head_cell);

//   if (!growing) {
//     // Remove the tail from the vector.
//     body.erase(body.begin());
//   } else {
//     growing = false;
//     size++;
//   }

//   // Check if the Target has died.
//   for (auto const &item : body) {
//     if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
//       alive = false;
//     }
//   }
// }

// void Target::GrowBody() { growing = true; }

// // Inefficient method to check if cell is occupied by Target.
bool Target::TargetCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  // for (auto const &item : body) {
  //   if (x == item.x && y == item.y) {
  //     return true;
  //   }
  // }
  return false;
}