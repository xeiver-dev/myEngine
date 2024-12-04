#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>
#include "SDL_events.h"
#include "SDL_render.h"
#include "SDL_video.h"

typedef struct {
  SDL_Window*   window;
  SDL_Renderer* renderer;
  SDL_Event     event;

  bool          running;
  int           width, height;
} Game;

void game__Init(Game* g, int width, int height);
void game__Draw(Game* g);
void game__Update(Game* g);
void game__ProcessEvents(Game* g);
void game__Close(Game* g);

#endif
