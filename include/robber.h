#ifndef Robber_H
#define Robber_H

#include <vector>
#include "SDL.h"
#include "target.h"

class Robber: public Target {
 public:
  // enum class Direction { kUp, kDown, kLeft, kRight };

  Robber(int grid_width, int grid_height):Target(grid_width,grid_height){}

  // getters
  int AskedAmount(){return asked_amount_;}

  // Setters
  void AskedAmount(int i){asked_amount_=i;}
  //     : grid_width(grid_width),
  //       grid_height(grid_height),
  //       head_x(grid_width / 2),
  //       head_y(grid_height / 2) {}

  // void Update();

  // // void GrowBody();
  // bool RobberCell(int x, int y);

  // Direction direction = Direction::kUp;

  // float speed{0.1f};
  // int size{1};
  // bool alive{true};
  // float head_x;
  // float head_y;
  // std::vector<SDL_Point> body;

 private:
 int asked_amount_;
//   void UpdateHead();
//   // void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

//   bool growing{false};
//   int grid_width;
//   int grid_height;
};

#endif