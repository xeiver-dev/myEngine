#ifndef ENGINE_H
#define ENGINE_H

#include "graphics.h"
#include "input.h"
#include "window.h"
#include <stdbool.h>

typedef struct {
  Window window;
  Graphics graphics;
  Input input;

  bool          running;
  int           width, height;
} Game;

void game__Initialize(Game* g, int width, int height);
void game__Render(Game* g);
void game__Update(Game* g);
void game__PollEvents(Game *g);
void game__Run(Game *g);
void game__Shutdown(Game* g);

#endif
