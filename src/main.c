#include "game.h"
int main(int argc, char *argv[])
{
  Game game = {0};

  game__Initialize(&game, 800, 600);

  while (game.running) 
  {
    game__Update(&game);
    game__Render(&game);
  }
  game__Shutdown(&game);

  return 0;
}
