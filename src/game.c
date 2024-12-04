#include "engine.h"
#include "SDL.h"
#include "SDL_events.h"
#include "SDL_keycode.h"
#include "SDL_render.h"
#include "SDL_video.h"

void game__Init(Game* g, int width, int height)
{
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
    exit(-1);
  }

  g->running = true;
  g->width = width;
  g->height = height;

  // Create a window that is centered
  g->window = SDL_CreateWindow("My Game Game", 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED,
                              g->width, g->height, SDL_WINDOW_SHOWN);
  // Check if window is null
  if (g->window == NULL)
  {
    fprintf(stderr, "Failed to create a window: %s\n", SDL_GetError());
    exit(-1);
  }

  // Create a renderer using the window and enable vsync and is accelerated
  g->renderer = SDL_CreateRenderer(g->window, -1,
                                   SDL_RENDERER_PRESENTVSYNC |
                                   SDL_RENDERER_ACCELERATED);
  // Checks if renderer is null, returns an error if it is null.
  if (g->renderer == NULL)
  {
    fprintf(stderr, "Failed to create a renderer: %s\n", SDL_GetError());
    exit(-1);
  }
}

void game__Draw(Game* g)
{
  // Clears the window
  SDL_RenderClear(g->renderer);
  // Sets the background color of the window (which is White in this case)
  SDL_SetRenderDrawColor(g->renderer, 255, 255, 255, 255);


  // Present the renderer to the window
  // shows the things that were drawn using the renderer
  SDL_RenderPresent(g->renderer);
}

void game__Update(Game* g)
{
}

void game__ProcessEvents(Game* g)
{
  // Poll window events (like quit or keydown)
  while (SDL_PollEvent(&g->event)) 
  {
    switch (g->event.type) 
    {
      case SDL_QUIT:
        g->running = false;
      case SDL_KEYDOWN:
        if (g->event.key.keysym.sym == SDLK_ESCAPE) 
        {
          g->running = false;
        }
      default:
        break;
    }
  }
}

void game__Shutdown(Game* g)
{
  SDL_DestroyRenderer(g->renderer);
  SDL_DestroyWindow(g->window);
  SDL_Quit();
}
