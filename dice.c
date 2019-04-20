#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* simulate dice rolling
   accepts two args: number of dice and sides of dice
   returns total dice roll */

int roll_dice(int num_die, int sides)
{
  srand(time(NULL)); // seed random with time value
  int total = 0;
  for (int i = 0; i < num_die; i++) 
  {
    int roll = rand() % sides + 1;
    printf("roll is %d\n", roll);
    total += roll;
  }
  printf("total roll is %d\n", total);
  return total;
}

int to_hit(int mod)
{
  /* accepts a to-hit modifier from the defender
     rolls a die, and returns true if hit is successful,
     false if hit is a miss
     base to-hit value is 15
     */
  int to_hit = 15;
  int roll = roll_dice(1, 20); // roll one 20-sided die
  if (roll >= to_hit - mod)
  {
    printf("hit\n");
    return 1;
  }
  printf("miss\n");
  return 0;
}

int main(void) {
  to_hit(5);
}

