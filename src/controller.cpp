#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "robber.h"
#include <algorithm>

void Controller::ChangeDirection(Robber &robber, Robber::Direction input,
                                 Robber::Direction opposite) const {
  if (robber.direction != opposite) robber.direction = input;
  return;
}

void Controller::AskForGold(bool &running, Robber &robber) const{
  std::cout << "Your gold or your life! I demand:  ([0 - 1000])" << std::endl;
  int gold;
  std::cin >> gold ;
  robber.AskedAmount(std::clamp(gold, 0,1000));
  std::cout << robber.AskedAmount()<< " gold charged!" << std::endl;
}

void Controller::HandleInput(bool &running, Robber &robber) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(robber, Robber::Direction::kUp,
                          Robber::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(robber, Robber::Direction::kDown,
                          Robber::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(robber, Robber::Direction::kLeft,
                          Robber::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(robber, Robber::Direction::kRight,
                          Robber::Direction::kLeft);
          break;
      }
    }
  }
}