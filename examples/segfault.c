#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print() {
  printf("hello world\n");
}

typedef void(*fptr)(void);

int main(int argc, char* argv) {
  fptr *fp = malloc(1);
  *fp = print;
  //free(fp);
  (*fp)();
  free(fp);
}
