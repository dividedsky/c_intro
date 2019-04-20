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

int main(void) {
  roll_dice(6, 20);
}

