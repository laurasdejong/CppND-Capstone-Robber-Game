#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "robber.h"

class Controller {
 public:
  void HandleInput(bool &running, Robber &robber) const;
  void AskForGold(bool &running, Robber &robber, int max_gold) const;

 private:
  void ChangeDirection(Robber &robber, Robber::Direction input,
                       Robber::Direction opposite) const;
};

#endif