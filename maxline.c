#include <stdio.h>
#define MAXLINE 1000

// function prototypes
int mgetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(void)
{
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = mgetline(line, MAXLINE)) > 0) {
    printf("len is %d\n", len);
    if (len > max) {
      max = len;
      copy(longest, line);
      printf("new long\n");
    }
  }
  if (max > 0) { // there was a line
    printf("longest line: %s", longest);
  }
  return 0;
}

/* read a line into s, return length */
int mgetline(char s[], int lim)
{
  int c, i;
  
  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  printf("i is %d\n", i);
  return i;
}

/* copy from into to */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    i++;
}
