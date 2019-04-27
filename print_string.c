#include <stdio.h>

void print_string(char *s);
int main(void) {
  char *my_string = "hello! hi!\n";
  print_string(my_string);

}

/* takes a character pointer and prints a string */
void print_string(char * s)
{
  for (int i = 0; *(s + i) != '\0'; i++) 
    printf("%c", *(s + i));
}
