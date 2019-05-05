#include <stdio.h>
#include "game.h"

// takes pointers to two players
// simulates combat until one player has no hp
// returns void?

void combat(Player *player, Player *enemy)
{
  int dmg;
  while (player->hitpoints > 0 && enemy->hitpoints > 0) {
    if (to_hit(5)) {
      dmg = dmg_roll(enemy->dmg_reduction, 0, 1, player->attack);
      printf("p hits for %d\n", dmg);
      enemy->hitpoints -= dmg;
      printf("%s has %d hp left\n", enemy->name, enemy->hitpoints);
    } else {
      printf("miss!\n");
    }
    

  }
}


