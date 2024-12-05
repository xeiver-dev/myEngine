#include "graphics.h"
#include "SDL_error.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "common.h"
#include "window.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void graphics__Init(Graphics *gp, Window *win)
{
  gp->renderer = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gp->renderer == NULL)
  {
    fprintf(stderr, "Failed to create a renderer: %s\n", SDL_GetError());
    exit(-1);
  }
}
void graphics__Clear(Graphics *gp, Color bgColor)
{
  SDL_SetRenderDrawColor(gp->renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  SDL_RenderClear(gp->renderer);
}

void graphics__Display(Graphics *gp)
{
  SDL_RenderPresent(gp->renderer);
}

void graphics__DrawRect(Graphics *gp, const char *mode,
                        SDL_Rect *rect, Color color)
{
  SDL_SetRenderDrawColor(gp->renderer, color.r, color.g, color.b, color.a);
  if (strcmp(mode, "line")) {
    SDL_RenderFillRect(gp->renderer, rect);
  } else if (strcmp(mode, "fill")) {
    SDL_RenderDrawRect(gp->renderer, rect);
  }
}

void graphics__DrawCircle(Graphics *gp, Circle *circle, Color color)
{
  SDL_SetRenderDrawColor(gp->renderer, color.r, color.g, color.b, color.a);
  
  for (int w = 0; w < circle->radius * 2; w++) 
  {
    for (int h = 0; h < circle->radius * 2; h++) 
    {
      int dx = circle->radius - w;
      int dy = circle->radius - h;
      if ((dx * dx + dy * dy) <= (circle->radius * circle->radius)) 
      {
        SDL_RenderDrawPoint(gp->renderer, circle->center.x + dx, circle->center.y + dy);
      }
    }
  }
}


SDL_Texture* graphics__LoadTexture(Graphics *gp, const char *file)
{
  SDL_Texture *tex = IMG_LoadTexture(gp->renderer, file); 
  return tex;
}

void graphics__DrawTexture(Graphics *gp, SDL_Texture *texture, SDL_Rect *src_rect, SDL_Rect *dst_rect)
{
  SDL_RenderCopy(gp->renderer, texture, src_rect, dst_rect);
}

void graphics__DestroyTexture(Graphics *gp, SDL_Texture *texture)
{
  SDL_DestroyTexture(texture);
}

void graphics__Quit(Graphics *gp)
{
  SDL_DestroyRenderer(gp->renderer);
  IMG_Quit();
}
