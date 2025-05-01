#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // create an array of size 5, but forgot to free it

  int size = 100;
  int *arr = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    *(arr + i) = 0;
  }

  free(arr + 20);

  // printf("Value for test %d\n", *(arr + 2));
}
