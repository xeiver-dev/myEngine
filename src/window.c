#include "window.h"
#include "SDL.h"
#include "SDL_video.h"

Window* window__Create(int w, int h)
{
  Window* win;
  win->width = w;
  win->height = h;

  win->window = SDL_CreateWindow(win->title, 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED,
                                 win->width, win->height, SDL_WINDOW_SHOWN);
  // Check if window is null
  if (win->window == NULL)
  {
    fprintf(stderr, "Failed to create a window: %s\n", SDL_GetError());
    exit(-1);
  }
  
  return win;
}

void window__SetTitle(Window *win, const char* t)
{
  win->title = t; 
}

Vector2 window__GetSize(Window* win)
{
  return (Vector2){win->width, win->height};
}

void window__PollEvents(Window* win)
{
  // Poll window events (like quit or keydown)
  while (SDL_PollEvent(&win->event)) 
  {
    switch (win->event.type) 
    {
      case SDL_QUIT:
        SDL_Quit();
        break;
      case SDL_KEYDOWN:
        if (win->event.key.keysym.sym == SDLK_ESCAPE) 
        {
          SDL_Quit();
          break;
        }
      default:
        break;
    }
  }
  
}
void window__Close(Window *win) 
{
  SDL_DestroyWindow(win->window);
}
