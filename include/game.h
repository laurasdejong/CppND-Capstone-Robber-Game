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
  int GetScore() const;
  // int GetSize() const;

 private:
  enum GameState{talk, walk};
  Robber robber_;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::chrono::time_point<std::chrono::system_clock> t_start_;

  int score{0};
  const long guild_time_ms_{1000}; //every second
  GameState mode_;

  void PlaceTarget();
  void Update();
  void RobbingTarget();
};

#endif