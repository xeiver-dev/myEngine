#include "game.h"
int main(int argc, char *argv[])
{
  Game *game;

  game__Initialize(game, 1280, 720);

  game__Run(game);
  game__Shutdown(game);

  return 0;
}
