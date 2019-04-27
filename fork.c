#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void get_dir(char *dir);

int main(int argc, char *argv[])
{
  if (argc != 0) {
    printf("argc is %d\n", argc);
  }
  printf("hello, world! (pid: %d)\n", (int) getpid());
  int x = 42;
  int rc = fork();
  char *test = malloc(100);
  get_dir(test);
  printf("test is %s\n", test);

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


    /*
    // trying to use getline to read STDIN is causing a segfault 
    char *line = NULL;
    size_t len = 0;
    ssize_t dir_name;
    dir_name = getline(&line, len, STDIN_FILENO);
    */
    /* char *dirname = malloc(100); */
    /* fgets(dirname, 100, stdin); */
    /* printf("dirname length is %ld\n", strlen(dirname)); */
    /* printf("dir name is %s\n", dirname); */
    printf("x is now %d at the address %p\n", x, &x);
    if (strlen(test) <= 1)  {
      test = ".";
      printf("dirname is now %s\n", test);
    }
    DIR *dir = opendir(test);

    struct dirent *file;
    while ((file = readdir(dir)) != NULL)
      printf("%s\n", file->d_name);
    closedir(dir);
  }

  return 0;
}

void get_dir(char *dir)
{
  char c;
  int i = 0;
  while ((c = getc(stdin)) != EOF && c != '\n') {
    *(dir + i) = c;
    i++;
  }
  printf("directory name is %s\n", dir);
}
