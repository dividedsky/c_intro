#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
  if (argc != 0) {
    printf("argc is %d\n", argc);
  }
  printf("hello, world! (pid: %d)\n", (int) getpid());
  int x = 42;
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed!\n");
    exit(1);
  } else if (rc == 0) {
    printf("child process here. (pid: %d)\n", (int) getpid());
    printf("x is %d and is at %p\n", x, &x);
    x = 41;
    printf("x is now %d at the address %p\n", x, &x);
  } else {
    printf("hello, parent here. (pid: %d) of child %d\n", (int) getpid(), rc );
    printf("x is %d and is at %p\n", x, &x);
    x = 23;
    printf("x is now %d at the address %p\n", x, &x);
    DIR *dir = opendir(".");
    struct dirent *file;
    while ((file = readdir(dir)) != NULL)
      printf("%s\n", file->d_name);
  }

  return 0;
}
