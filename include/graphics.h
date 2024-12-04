#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL_rect.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include "common.h"
#include "window.h"
typedef struct {
  SDL_Renderer *renderer;
} Graphics;

typedef struct {
  Vector2 center;
  int radius;
} Circle;

void graphics__Init(Graphics *gp, Window *win);
void graphics__Display(Graphics *gp);
void graphics__Clear(Graphics *gp, Color bgColor);

// Method for drawing shapes
void graphics__DrawRect(Graphics *gp, const char *mode, SDL_Rect *rect, Color color);
void graphics__DrawCircle(Graphics *gp, Circle *circle, Color color);

// Method for loading, drawing and clearing a texture
SDL_Texture* graphics__LoadTexture(Graphics *gp, const char *file);
void graphics__DrawTexture(Graphics *gp, SDL_Texture *texture, SDL_Rect *src_rect, SDL_Rect *dst_rect);
void graphics__DestroyTexture(Graphics *gp, SDL_Texture *texture);

void graphics__Quit(Graphics *gp);

#endif
