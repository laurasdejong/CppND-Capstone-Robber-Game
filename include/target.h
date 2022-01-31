#ifndef Target_H
#define Target_H

#include <vector>
#include "SDL.h"
#include <iostream>

class Target {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Target(int grid_width, int grid_height)
      : alive_(true),
        direction(Direction::kUp),
        gold_(10),
        grid_width(grid_width),
        grid_height(grid_height),
        head_x_(grid_width / 2),
        head_y_(grid_height / 2),
        speed_(0.08f){}

// Getters
  bool Alive() const {return alive_;}
  int Gold() const {return gold_;}
  float X() const {return head_x_;}
  float Y() const {return head_y_;}


// Setters
  void X(float x){head_x_ =x;};
  void Y(float y){head_y_ =y;};

// Functions
  void AddGold(int gold){gold_+=gold;}
  void PayGold(int gold){gold_-=gold;}
  void Update();
  bool TargetCell(int x, int y);

  Direction direction;
  int grid_width;
  int grid_height;

 private:
  bool alive_;
  int gold_;
  float head_x_;
  float head_y_;
  float speed_;
};

#endif