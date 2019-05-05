#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Player {
  char *name;
  int hitpoints;
  int armor_class;
  int attack;
  int dmg_reduction;
} Player;

/* reference to see type sizes */
void sizes(void) {
  // print dashes
  // since I'm going to do this multiple times, I'll use a pointer
  char *message = "SIZEOF LIST";
  printf("%s\n", message);
  for (int i = 0; i < strlen(message); i++) {
    printf("-");
  }
  printf("\n");
  printf("%-10s\%lu\n", "char:", sizeof(char));
  printf("%-10s\%lu\n", "Int:", sizeof(int));
  printf("%-10s\%lu\n", "Long:", sizeof(long));
  printf("%-10s\%lu\n", "float:", sizeof(float));
  printf("%-10s\%lu\n", "double:", sizeof(double));
  printf("%-10s\%lu\n", "pointer:", sizeof(int*));
  printf("%-10s\%lu\n", "Player:", sizeof(Player));
  printf("\n\n");
}

Player *make_player(char *name, int hp, int ac, int att, int dmg_reduction) {
  int len = strlen(name);
  printf("length is %d\n", len);
  Player *player = malloc(sizeof(Player));
  player->name = name;
  printf("player name is %s\n", player->name);
  player->hitpoints = hp;
  player->armor_class = ac;
  player->attack = att;
  return player;

}

void print_player(Player *player) 
{
  printf("Name: %s\n", player->name);
  printf("hitpoints: %d\n", player->hitpoints);
  printf("armor class: %d\n", player->armor_class);
}

void destroy_player(Player *player)
{
  /* free(player->name); */
  free(player);
}

int main(void) {
  /* Player player; /1* this does work, but I'm going to use my function for now *1/ */
  sizes();
  char *name = "justin";
  Player *player = make_player(name, 20, 10, 5, 1);
  print_player(player);
  printf("size of player is %lu\n", sizeof(*player));
  destroy_player(player);
  return 0;
}
