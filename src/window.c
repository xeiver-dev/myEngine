#include "window.h"
#include "SDL.h"
#include "SDL_video.h"

void window__Initialize(Window *win, int w, int h, const char* title)
{
  win->window = SDL_CreateWindow(title, 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED,
                                 w, h, SDL_WINDOW_SHOWN);
  // Check if window is null
  if (win->window == NULL)
  {
    fprintf(stderr, "Failed to create a window: %s\n", SDL_GetError());
    exit(-1);
  }
}

Vector2 window__GetSize(Window* win)
{
  return (Vector2){win->width, win->height};
}

void window__Close(Window *win) 
{
  SDL_DestroyWindow(win->window);
}
