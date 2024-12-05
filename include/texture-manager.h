#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "SDL_render.h"
#include "graphics.h"

#define MAX_TEXTURES 100

typedef struct {
  SDL_Texture **textures;
  int texture_counter;
} TextureManager;

void texture_manager__Init(TextureManager *tm);
void texture_manager__Update(TextureManager *tm);
void texture_manager__Add(TextureManager *tm, SDL_Texture *texture);
void texture_manager__Draw(TextureManager *tm, Graphics* graphics);
void texture_manager__Close(TextureManager *tm, Graphics* graphics);
#endif
