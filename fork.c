#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  if (argc != 0) {
    printf("argc is %d\n", argc);
  }
  printf("hello, world! (pid: %d)\n", (int) getpid());
  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed!\n");
    exit(1);
  } else if (rc == 0) {
    printf("child process here. (pid: %d)\n", (int) getpid());
  } else {
    printf("hello, parent here. (pid: %d) of child %d\n", (int) getpid(), rc );
  }

  return 0;
}
