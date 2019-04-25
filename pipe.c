#include <stdio.h>
#include <unistd.h>

int main(void) 
{
char buf[128];
    int fd[2];

    // fd[0] read end
    // fd[1] write end
    pipe(fd);

    write(fd[1], "Hello, worrrrrrr...\n", 21);

    read(fd[0], buf, sizeof buf);

    printf(buf);
}
