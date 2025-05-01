// From tiny step, baby step :))

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *arr;
  int size;
  int capacity;
} Vector;

Vector *init_vector() {
  Vector *v = malloc(sizeof(Vector));
  v->arr = NULL;
  v->size = 0;
  v->capacity = 0;

  return v;
}

void push_back(Vector *v, int value) {
  /*
  size = 0
  size > 0
    size = capacity
  */
  if (v->size == 0) {
    v->capacity = 1;
    v->arr = (int *)malloc(v->capacity * sizeof(int));
  } else if (v->size == v->capacity) {
    v->capacity = v->capacity * 2;
    v->arr = realloc(v->arr, v->capacity * sizeof(int));

    if (v->arr == NULL) {
      printf("Realloc failed, dont have enough space\n");

      return;
    }
  }
  v->size++;

  *(v->arr + v->size - 1) = value;
}

int get_value(Vector *v, int index) {
  if (index >= v->size) {
    printf("Index exceed\n");
    return -1;
  }

  return *(v->arr + index);
}

void free_vector(Vector *v) {
  free(v->arr);
  free(v);
}

int main(int argc, char *argv[]) {
  Vector *v = init_vector();

  push_back(v, 1);
  push_back(v, 5);

  printf("Value is %d\n", get_value(v, 1));

  free_vector(v);
}