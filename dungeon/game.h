typedef struct Player {
  char *name;
  int hitpoints;
  int armor_class;
  int attack;
  int dmg_reduction;
} Player;

int roll_dice(int n, int s);
int to_hit(int m);
int dmg_roll(int d, int db, int dd, int ds);
void combat(Player *player, Player *enemy);
