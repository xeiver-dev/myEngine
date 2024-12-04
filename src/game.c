#include "game.h"
#include "SDL.h"
#include "graphics.h"
#include "input.h"
#include "window.h"
#include <stdio.h>

void game__Initialize(Game* g, int width, int height)
{
  // Initialize SDL2
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    fprintf(stderr, "Failed to initialize SDL: %s\n", SDL_GetError());
    exit(-1);
  }

  g->running = true;

  window__Initialize(&g->window, width, height, "My Game Engine");

  graphics__Init(&g->graphics, &g->window);
  input__Init(&g->input);

}
void game__Render(Game* g)
{
  Color bgColor = (Color){100, 100, 100, 255};
  graphics__Clear(&g->graphics, bgColor);

  // Draws a circle in 200, 200 coordinate
  Circle  c = (Circle){(Vector2){200, 200}, 20};
  Color cColor = (Color){255, 0, 0, 255};
  graphics__DrawCircle(&g->graphics, &c, cColor);

  // Draws a huge rectangle on the side of the circle
  SDL_Rect rect = (SDL_Rect){500, 200, 45, 50};
  Color rectColor = (Color){0, 255, 255, 255};
  graphics__DrawRect(&g->graphics, "fill", &rect, rectColor);


  graphics__Display(&g->graphics);
}

void game__Update(Game* g)
{
  input__Update(&g->input);

  if (input__IsKeyPressed(&g->input, SDL_SCANCODE_SPACE)) {
    printf("Space key is pressed\n");
  }
}

void game__PollEvents(Game *g) 
{
  // Poll window events (like quit or keydown)
  while (SDL_PollEvent(&g->window.event)) 
  {
    switch (g->window.event.type) 
    {
      case SDL_QUIT:
        g->running = false;
        break;
      case SDL_KEYDOWN:
        if (g->window.event.key.keysym.sym == SDLK_ESCAPE) 
        {
          g->running = false;
        }
        break;
      default:
        break;
    }
  }

}

void game__Run(Game* g)
{
  while (g->running) 
  {
    game__Update(g);
    game__PollEvents(g);
    game__Render(g);
  }
}

void game__Shutdown(Game* g)
{
  window__Close(&g->window);
  graphics__Quit(&g->graphics);
  SDL_Quit();
}
