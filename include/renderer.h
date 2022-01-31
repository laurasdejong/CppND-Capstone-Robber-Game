#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "robber.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Robber const robber, Target const target,std::vector<SDL_Point> deaths);
  void UpdateWindowTitle(int score, int fps);
  void DrawEyes(float x, float y);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif