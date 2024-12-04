#ifndef WINDOW_H
#define WINDOW_H

#include "SDL_events.h"
#include "SDL_video.h"
#include "common.h"

typedef struct {
  SDL_Window* window;
  SDL_Event   event;

  int width, height;
  const char* title;
} Window;

Window* window__Create(int w, int h);
void window__SetTitle(Window* win, const char* t); 
Vector2 window__GetSize(Window* win);
void window__PollEvents(Window* win);
void window__Close(Window* win);

#endif
