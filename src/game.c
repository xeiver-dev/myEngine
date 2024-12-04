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

  window__Initialize(g->window, width, height, "My Game Engine");

  graphics__Init(g->graphics, g->window);
  input__Init(g->input);

}
void game__Render(Game* g)
{
  Color bgColor = (Color){100, 100, 100, 255};
  graphics__Clear(g->graphics, bgColor);

  Circle  c = (Circle){(Vector2){200, 200}, 20};
  Color cColor = (Color){255, 0, 0, 255};
  graphics__DrawCircle(g->graphics, &c, cColor);

  graphics__Display(g->graphics);
}

void game__Update(Game* g)
{
  input__Update(g->input);

  window__PollEvents(g->window, g->running);

  if (input__IsKeyPressed(g->input, SDL_SCANCODE_SPACE)) {
    printf("Space key is pressed");
  }
}
void game__Run(Game* g)
{
  while (g->running) 
  {
    game__Update(g);
    game__Render(g);
  }
}

void game__Shutdown(Game* g)
{
  window__Close(g->window);
  graphics__Quit(g->graphics);
  SDL_Quit();
}
