#include "input.h"
#include "SDL_keyboard.h"
#include "SDL_mouse.h"
#include "common.h"

void input__Init(Input *i)
{
  i->keyState = SDL_GetKeyboardState(NULL);
  i->mousePos = (Vector2){0, 0};
  i->mouseButtons = 0;
}
void input__Update(Input *i)
{
  // Update mouse position and button state
  i->mouseButtons = SDL_GetMouseState(&i->mousePos.x, &i->mousePos.y);
}

bool input__IsKeyPressed(Input *i, SDL_Scancode key)
{
  return i->keyState[key];
}
bool input__IsMouseButtonPressed(Input *i, Uint32 button)
{
  return (i->mouseButtons & SDL_BUTTON(button)) != 0;
}
Vector2 input__GetMousePosition(Input *i)
{
  return i->mousePos;
}
