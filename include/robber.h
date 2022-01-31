#ifndef Robber_H
#define Robber_H

#include <vector>
#include "SDL.h"
#include "target.h"

class Robber: public Target {
 public:

  Robber(int grid_width, int grid_height):Target(grid_width,grid_height){}

  // getters
  int AskedAmount(){return asked_amount_;}

  // Setters
  void AskedAmount(int i){asked_amount_=i;}

  // Functions
  void PayRobbersGuild();


 private:
 int asked_amount_;

};

#endif