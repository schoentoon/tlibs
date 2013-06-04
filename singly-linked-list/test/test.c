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
  printf("[PRINT] Number: %d\n", test->number);
  return 0;
};

void tearDownTest(void* ptr) {
  test* test = ptr;
  printf("[TEARDOWN] Tearing down node with number: %d\n", test->number);
  free(test);
};

int main(int argc, char** argv) {
  test* test = malloc(sizeof(test));
  test->number = 1;
  singly_linked_list* sll = new_singly_linked_list(test);
  int i;
  for (i = 2; i <= 10; i++) {
    test = malloc(sizeof(test));
    test->number = i;
    sll_append(sll, test);
  };
  printf("[TEST] Counting the elements.\n");
  printf("[COUNT] We have %d elements.\n", sll_count_list(sll));
  printf("[TEST] Printing all elements.\n");
  sll_for_each(sll, printTest);
  printf("[TEST] Removing 4th element.\n");
  sll_remove_item_at(sll, 4, tearDownTest);
  printf("[TEST] Removing 1st element.\n");
  sll_remove_item(sll, sll_get_item_at(sll, 1), tearDownTest);
  printf("[TEST] Removing 5th element.\n");
  sll_remove_item(sll, sll_get_item_at(sll, 5), tearDownTest);
  printf("[TEST] Counting the elements.\n");
  printf("[COUNT] We have %d elements.\n", sll_count_list(sll));
  printf("[TEST] Printing all elements.\n");
  sll_for_each(sll, printTest);
  printf("[TEST] Printing 5th element.\n");
  printTest(sll_get_item_at(sll, 5));
  printf("[TEST] Tearing everything down.\n");
  sll_teardown(sll, tearDownTest);
  return 0;
};
