#include <stdio.h>

void print_string(char *s);
int main(void) {
  char *my_string = "hello! hi!\n";
  char array_string[] = "this is an array\n";
  print_string(my_string);
  print_string(array_string);

}

/* takes a character pointer and prints a string */
/* this works fine with an array string, as well,
   because when the array string is passed, it's 
   simply passed as a pointer */
void print_string(char * s)
{
  for (int i = 0; *(s + i) != '\0'; i++) 
    printf("%c", *(s + i));
}
