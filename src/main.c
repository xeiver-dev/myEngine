#include "game.h"
int main(int argc, char *argv[])
{
  Game *game;

  game__Initialize(game, 800, 600);

  game__Run(game);
  game__Shutdown(game);

  return 0;
}
