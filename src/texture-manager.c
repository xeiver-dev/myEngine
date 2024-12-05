#include "texture-manager.h"
#include "SDL_render.h"
#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>

void texture_manager__Init(TextureManager *tm){
  tm->textures = (SDL_Texture**)malloc(MAX_TEXTURES * sizeof(SDL_Texture*));
  if (tm->textures == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(-1);
  }
  tm->texture_counter = 0;
}

void texture_manager__Update(TextureManager *tm) {

}
void texture_manager__Add(TextureManager *tm, SDL_Texture *texture) {
  if (tm->texture_counter < MAX_TEXTURES) {
    tm->textures[tm->texture_counter] = texture;
    tm->texture_counter++;
  } else {
    fprintf(stderr, "Error: Maximum texture limit reached\n");
  }
}

void texture_manager__Draw(TextureManager *tm, Graphics* graphics) {
  graphics__DrawTexture(graphics, tm->textures[tm->texture_counter - 1], &(SDL_Rect){0, 0, 16, 16}, &(SDL_Rect){0, 0, 64, 64});
}
void texture_manager__Close(TextureManager *tm, Graphics* graphics){
  for (int i = 0;i < tm->texture_counter; i++) {
    graphics__DestroyTexture(graphics, tm->textures[i]);
  }

  free(tm->textures);
  tm->texture_counter = 0;
}
