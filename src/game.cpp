#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : robber_(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      mode_(GameState::walk) {
  PlaceTarget();
}

void Game::Play(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    if (mode_ == GameState::walk){
      // Input, Update, Render - the main game loop.
      controller.HandleInput(running, robber_);
      Update();
      renderer.Render(robber_, food);
      robber_.PayRobbersGuild();
    } else {
      controller.AskForGold(running, robber_);
      RobbingTarget();
      std::cout << "Robber now has: " << robber_.Gold()<< std::endl;
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceTarget() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a robber item before placing
    // food.
    if (!robber_.TargetCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::RobbingTarget(){
  int temp_target = 60;
  if (temp_target < robber_.AskedAmount()){
    std::cout << "Your life then!" << std::endl;
    robber_.AddGold(temp_target);
  } else {
    std::cout << "Stealing your gold! Bye!" << std::endl;
    robber_.AddGold(robber_.AskedAmount());
  }
  mode_ = GameState::walk;
}

void Game::Update() {
  if (!robber_.Alive()) return;

  robber_.Update();

  int new_x = static_cast<int>(robber_.head_x);
  int new_y = static_cast<int>(robber_.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    mode_ = GameState::talk;
    score++;
    PlaceTarget();
    // Grow robber and increase speed.
    // robber.GrowBody();
    // robber.speed += 0.02;
  }

  // check every once in a while
  // Pay robbersGuild
  // Spawn
}

int Game::GetScore() const { return robber_.Gold(); }
// int Game::GetSize() const { return robber_.size; }