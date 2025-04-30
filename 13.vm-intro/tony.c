/*
  write a program that take input from command line argument,
  which is the total MB that this program will take.

  run this program, and see the virtual memory usage
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  long pid = (long)getpid();

  printf("Process ID: %ld\n", pid);

  if (argc != 2)
    return 0;

  int input = atoi(argv[1]);
  if (input == 0)
    return 0;

  // Create an array in Stack with the size of {input} Mebibytes
  long totalElement = input * 1024 * 1024 / 8; // array of long

  printf("Total element is %ld\n", totalElement);

  long *array = calloc(totalElement, sizeof(long));

  while (1) {
    for (int i = 0; i < totalElement; i++) {
      long tmp = array[i];
    }
  }
}