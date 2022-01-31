#ifndef Target_H
#define Target_H

#include <vector>
#include "SDL.h"

class Target {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Target(int grid_width, int grid_height)
      : gold(0),
        grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        speed(0.1f),
        size(1),
        alive(true){}

  void Update();

  // void GrowBody();
  bool TargetCell(int x, int y);

  Direction direction = Direction::kUp;

  float speed;
  int size;
  bool alive;
  float head_x;
  float head_y;
  // std::vector<SDL_Point> body;

  // void UpdateHead();
  // void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  // bool growing{false};
  int grid_width;
  int grid_height;
  int gold;

  private:
  float townsize_;
};

#endif