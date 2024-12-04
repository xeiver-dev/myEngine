#ifndef WINDOW_H
#define WINDOW_H

#include "SDL_events.h"
#include "SDL_video.h"
#include "common.h"
#include <stdbool.h>

typedef struct {
  SDL_Window* window;
  SDL_Event   event;

  int width, height;
  const char* title;
} Window;

void window__Initialize(Window* win, int w, int h, const char *title);
Vector2 window__GetSize(Window* win);
void window__Close(Window* win);

#endif
