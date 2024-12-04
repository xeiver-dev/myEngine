#ifndef ENGINE_H
#define ENGINE_H

#include "window.h"
#include <stdbool.h>

typedef struct {
  Window* window;

  bool          running;
  int           width, height;
} Game;

void game__Initialize(Game* g, int width, int height);
void game__Render(Game* g);
void game__Update(Game* g);
void game__Run(Game *g);
void game__Shutdown(Game* g);

#endif
