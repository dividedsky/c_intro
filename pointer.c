#include <stdio.h>

int main(void) 
{
  char *s = "this is a string";
  printf("%p is the address\n", s); // this is the pointer's address in memory
  printf("%d is the value\n", *s); /* this should be the value of the pointer, now it's 116(t).
                                      that's because the dereference only gets us to the first position 
                                      where the pointer points, not the whole string. how do we get the 
                                      whole string, then? */
  char s1[] = "this is another string"; //declaring an array. 
  printf("%s\n", s1); // this works as you would expect it to
  char *p1 = s1;
  printf("p1 is %p\n", p1);
  printf("value is %d\n", *p1); // same problem as above here--this only gets the value of the first char
}

