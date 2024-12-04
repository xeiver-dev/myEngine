#ifndef INPUT_H
#define INPUT_H

#include "SDL_scancode.h"
#include "SDL_stdinc.h"
#include "common.h"
#include <stdbool.h>

typedef struct {
  const Uint8 *keyState;
  Vector2 mousePos;
  Uint32 mouseButtons;
} Input;

void input__Init(Input *i);
void input__Update(Input *i);
bool input__IsKeyPressed(Input *i, SDL_Scancode key);
bool input__IsMouseButtonPressed(Input *i, Uint32 button);
Vector2 input__GetMousePosition(Input *i);

#endif
