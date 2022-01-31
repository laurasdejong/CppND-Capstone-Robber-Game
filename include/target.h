#ifndef Target_H
#define Target_H

#include <vector>
#include "SDL.h"

class Target {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Target(int grid_width, int grid_height)
      : alive_(true),
        direction(Direction::kUp),
        gold_(0),
        grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        speed_(0.08f){}

// Getters
  bool Alive() const {return alive_;}
  int Gold() const {return gold_;}


// Setters

// Functions
  void AddGold(int gold){gold_+=gold;}
  void Update();
  bool TargetCell(int x, int y);

  Direction direction;

  float speed_;
  // int size;
  // bool alive_;
  float head_x;
  float head_y;
  // std::vector<SDL_Point> body;

  // void UpdateHead();
  // void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  // bool growing{false};
  int grid_width;
  int grid_height;

  private:
  bool alive_;
  int gold_;
  float townsize_;
};

#endif