#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void reuse_memory() {
  char* s = malloc(1000);
  memset(s, 'X', 1000);
}

int main(int argv, char* argc) {
  char* s = malloc(1000);
  strcpy(s, "hello world\n");
  free(s);
  //reuse_memory();
  printf("%s", s);
  free(s);
}

