#include "game.h"
#include "SDL.h"
#include <stdbool.h>

void game__Initialize(Game* g, int width, int height)
{
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
    exit(-1);
  }

  g->running = true;

  g->window = window__Create(width, height);
}
void game__Draw(Game* g)
{
}

void game__Update(Game* g)
{
}


void game__Shutdown(Game* g)
{
  window__Close(g->window);
  SDL_Quit();
}
