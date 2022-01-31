#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Robber Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Robber const robber, Target const target) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0, 232, 99, 0.8);
  SDL_RenderClear(sdl_renderer);

  // Render target
  block.x = static_cast<int>(target.X()) * block.w;
  block.y = static_cast<int>(target.Y()) * block.h;
  SDL_SetRenderDrawColor(sdl_renderer, 214, 124, 22, 0.8);
  SDL_RenderFillRect(sdl_renderer, &block);
  DrawEyes(target.X(),target.Y());

  // Render robber
  block.x = static_cast<int>(robber.X()) * block.w;
  block.y = static_cast<int>(robber.Y()) * block.h;
  if (robber.Alive()) {
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 0.8);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 20, 103, 154, 0.8);
  }
  SDL_RenderFillRect(sdl_renderer, &block);
  DrawEyes(robber.X(),robber.Y());


  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Robbed gold: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::DrawEyes(float x, float y){
  SDL_Rect block2;
  block2.w = screen_width / (grid_width*5);
  block2.h = screen_height / (grid_height*5);
     // Render robber's eyes
  block2.x = static_cast<int>(x) * (screen_width /grid_width)+block2.w;
  block2.y = static_cast<int>(y) * (screen_width /grid_width) +block2.h;
  SDL_SetRenderDrawColor(sdl_renderer, 200, 100, 10, 0.8);
  SDL_RenderFillRect(sdl_renderer, &block2); //left
  block2.x = static_cast<int>(x) * (screen_width /grid_width) +3*block2.w;
  SDL_RenderFillRect(sdl_renderer, &block2); //right
}