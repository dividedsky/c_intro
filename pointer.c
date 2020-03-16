#include <stdio.h>
#include <stdlib.h>

/* function to print out a string. takes a pointer value, prints every char in that string until it reaches
   a null value */
void print_string(char *str)
{
  printf("inside print_string function\n");
  /* printf("%c\n", *str); */
  for (int i = 0;; i++) {
    char idx = sizeof(char) * i;
    /* printf("idx is %d\n", idx); */
    if (*(str + idx) == '\0') {
      printf("\n");
      break;
    }
    printf("%c", *(str + sizeof(char) * i));
  }
}

void pointer_test(void)
{
  int *p = malloc(sizeof(int *));
  int **q = &p;
  int a[] = {4, 8, 15, 16, 23, 42};
  p = &a[1];
  q = &p;
  printf("p and q initialized. the value of p,q is %d,%d. Adress of p,q is %p,%p\n", *p, **q, p, q);
  p++;
  printf("address of a[2] is %p\n", &a[2]);
  printf("p has been incremented. the value of p,q is %d,%d. Adress of p,q is %p,%p\n", *p, **q, p, q);
}

int main(void) 
{
  char *s = "this is a string";
  printf("%p is the address\n", s); // this is the pointer's address in memory
  printf("%d is the value\n", *s); /* this should be the value of the pointer, now it's 116(t).
                                      that's because the dereference only gets us to the first position 
                                      where the pointer points, not the whole string. how do we get the 
                                      whole string, then? */
  char s1[] = "this is another string"; //declaring an array. 
  printf("%s\n", s);
  printf("%s\n", s1); // this works as you would expect it to
  char *p1 = s1;
  printf("p1 is %p\n", p1); // prints the address of p1
  printf("value is %d\n", *p1); // same problem as above here--this only gets the value of the first char
  printf("value is %c\n", *p1); // and this prints just the first character, not the whole string
  printf("value is %c\n", (*p1 + 1)); /* trying to use pointer arithmetic, but this does not work. this will
                                         print 'u' because it dereferences to t, then adds 1 => u */
  printf("second char is %c\n", *(p1 + 1)); // this correctly dereferences the second char
  pointer_test();


  // memory allocation
  // malloc takes in one param: the amt of memory in bytes to be allocated
  // malloc will find a contiguous spot in memory that satisfies the size requirement
  // malloc returns a pointer to the first block of memory

  int *mall_int = malloc(100 * sizeof(int)); // block of memory that holds 100 ints ( 100 * 4(?) )
  printf("the address of mall_int is %p\n", mall_int);
  printf("the value at mall_int is%d\n", *mall_int); /* what happens if we dereference? this returns a 0, but I'm pretty sure it could
                                return a garbage value. we've allocated the memory, but we haven't assigned any
                                integers to it */
  for (int i = 0; i < 100; i++) {
    int ran = rand() % 100; // random value < 100
    /* printf("%d\n", ran); */
    *(mall_int + i) = ran; // assign a random value to this block of memory
  }
  printf("first value is %d\n", *mall_int);


  /* by passing pointers to functions, we can allow those functions to update the original values */

  char *myString = "this is some string";
  print_string(myString);
}

