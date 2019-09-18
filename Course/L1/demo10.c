#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr;
  ptr = malloc(10*sizeof(*ptr));  /* a block of 10 ints */
  if (ptr != NULL) {
    *(ptr+2) = 50;  /* assign 50 to third int */
  }
  ptr = realloc(ptr, 100*sizeof(*ptr)); /* 100 ints */
  *(ptr+30) = 75;
  printf("%d %d\n", *(ptr+2), *(ptr+30));

  return 0;
}
