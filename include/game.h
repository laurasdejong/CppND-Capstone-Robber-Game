#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "robber.h"
#include <iostream>
#include <thread>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Play(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);

  //Getters
  int GetScore() const;
  int GetMaxGold(){return max_gold_;};

 private:
  enum GameState{talk, walk};

  // functions
  void PlaceTarget();
  void Update();
  void RobbingTarget();

  // variables
  std::vector<SDL_Point> deaths_;
  const long guild_time_ms_;
  SDL_Point last_position_;
  int max_gold_;
  GameState mode_;
  Robber robber_;
  std::chrono::time_point<std::chrono::system_clock> t_start_;
  Target target_;

  // Random
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
};

#endif