#include "game.h"
int main(int argc, char *argv[])
{
  Game game = {0};

  game__Init(&game, 800, 600);

  while (game.running) 
  {
    game__ProcessEvents(&game);
    game__Update(&game);
    game__Draw(&game);
  }
  game__Close(&game);

  return 0;
}
