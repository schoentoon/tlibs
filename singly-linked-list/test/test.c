/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#include "linked-list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int number;
} test;

int printTest(void* ptr) {
  test* test = ptr;
  printf("Number: %d\n", test->number);
  return 0;
};

void tearDownTest(void* ptr) {
  test* test = ptr;
  printf("Tearing down node with number: %d\n", test->number);
};

int main(int argc, char** argv) {
  test* test = malloc(sizeof(test));
  test->number = 1;
  struct sll_node* front = new_sll_node(test);
  int i;
  for (i = 2; i <= 10; i++) {
    test = malloc(sizeof(test));
    test->number = i;
    sll_append(front, test);
  };
  printf("struct sll_node* front has %d items.\n", sll_count_list(front));
  sll_for_each(front, printTest);
  sll_teardown(front, tearDownTest);
  return 0;
};