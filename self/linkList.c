/*
  Implement linked-list data structure in C programming language

  As a user, I only care that I can add element and access that element
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

Node *init_node(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    printf("Fail to create the node\n");
  }
  node->value = value;
  node->next = NULL;

  return node;
}

LinkedList *init_linked_list() {
  LinkedList *linkedList = (LinkedList *)malloc(sizeof(LinkedList));
  linkedList->head = init_node(0);
  linkedList->tail = linkedList->head;
  linkedList->size = 0;

  return linkedList;
}

void add_node(LinkedList *list, Node *node) {
  list->tail->next = node;
  list->tail = node;
  list->size++;
}

int get_node_value(LinkedList *list, int index) {
  if (index >= list->size) {
    printf("Invalid index\n");
    return -1;
  }

  Node *travel = list->head;
  int currentIndex = -1;
  while (currentIndex <= index) {
    if (currentIndex == index) {
      return travel->value;
    }
    travel = travel->next;
    currentIndex++;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    return 0;
  }

  char *endptr = NULL;

  int index = strtol(argv[1], &endptr, 10);

  // store the address of the first invalid character in *ptr
  if (endptr != NULL) {
    if (strcmp(endptr, argv[1]) == 0) {
      printf("Go to this case, value is %s\n", endptr);
    }
    printf("Invalid value is %c\n", *endptr);
    printf("Invalid argument\n");
    return 0;
  }

  LinkedList *list = init_linked_list();
  Node *node1 = init_node(2002);
  Node *node2 = init_node(12);

  add_node(list, node1);
  add_node(list, node2);

  printf("Value is %d\n", get_node_value(list, index));
}