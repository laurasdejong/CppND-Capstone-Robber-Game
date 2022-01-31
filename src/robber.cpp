#include "robber.h"
#include <cmath>
#include <iostream>
#include <random>

void Robber::PayRobbersGuild(){
    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(1,5); // source: Udacity Program a Concurrent Traffic Light

    PayGold(distr(eng));
        // gold_-=50;
}

// void Robber::Update() {
//   SDL_Point prev_cell{
//       static_cast<int>(head_x),
//       static_cast<int>(
//           head_y)};  // We first capture the head's cell before updating.
//   UpdateHead();
//   SDL_Point current_cell{
//       static_cast<int>(head_x),
//       static_cast<int>(head_y)};  // Capture the head's cell after updating.

//   // Update all of the body vector items if the Robber head has moved to a new
//   // cell.
//   // if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
//   //   UpdateBody(current_cell, prev_cell);
//   // }
// }

// void Robber::UpdateHead() {
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

//   // Wrap the Robber around to the beginning if going off of the screen.
//   head_x = fmod(head_x + grid_width, grid_width);
//   head_y = fmod(head_y + grid_height, grid_height);
// }

// // void Robber::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
// //   // Add previous head location to vector
// //   body.push_back(prev_head_cell);

// //   if (!growing) {
// //     // Remove the tail from the vector.
// //     body.erase(body.begin());
// //   } else {
// //     growing = false;
// //     size++;
// //   }

// //   // Check if the Robber has died.
// //   for (auto const &item : body) {
// //     if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
// //       alive = false;
// //     }
// //   }
// // }

// // void Robber::GrowBody() { growing = true; }

// // // Inefficient method to check if cell is occupied by Robber.
// bool Robber::RobberCell(int x, int y) {
//   if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
//     return true;
//   }
//   // for (auto const &item : body) {
//   //   if (x == item.x && y == item.y) {
//   //     return true;
//   //   }
//   // }
//   return false;
// }