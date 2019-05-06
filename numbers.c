# include <stdio.h>

void print_nums(void) {
  for (int i = 0; i < 100; i++) {
    printf("-------\n");
    printf("dec: %d\nhex: %x\n", i, i);
  }
}

void shift(int *num)
{
  printf("num is %d\n", *num);
  /* *num = *num>>3; */
  while (*num > 0) {
    /* printf("%d", *((num)&1 == 0) ? '0' : '1'); */
    if ((*num & 1) == 1) {
      printf("0");
    } else {
      printf("1");
    }
    *num = *num>>1;
  }
  printf("\n");
}
int main(void) 
{
  for (int i = 0; i < 64; i++) {
  int x = i;
  shift(&x);
  }
}
