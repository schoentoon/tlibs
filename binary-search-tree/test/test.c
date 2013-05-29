/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#include "binary-search-tree.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  char* key;
  int random;
} test;

test* create_test(char* key) {
  test* output = malloc(sizeof(test));
  output->key = strdup(key);
  output->random = rand();
  return output;
};

test* random_test() {
  static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  size_t len = rand() % 16;
  len += 16;
  char key[len + 1];
  int i;
  for (i = 0; i < len; i++)
    key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  key[len] = '\0';
  return create_test(key);
};

void printTest(void* ptr) {
  test* test = ptr;
  printf("[PRINT] Key '%s', random %d\n", test->key, test->random);
};

int test_compare(void* ptr1, void* ptr2) {
  return strcmp(((test*) ptr1)->key, ((test*) ptr2)->key);
};

int test_compare_key(void* ptr, void* key) {
  return strcmp(((test*) ptr)->key, (char*) key);
};

void teardown_test(void* ptr) {
  printf("[TEARDOWN] Tearing down leaf at %p.\n", ptr);
  test* test = ptr;
  if (test->key)
    free(test->key);
  free(test);
};

int main(int argc, char** argv) {
  srand(time(NULL)^getpid());
  test* test = create_test("This is a key");
  bst_roots* root = new_bst_tree(test);
  test = create_test("This is another key");
  bst_grow_leaf(root, test, test_compare);
  test = create_test("Now for some random strings");
  bst_grow_leaf(root, test, test_compare);
  int leaves = rand() % 32;
  leaves += 16;
  int i;
  for (i = 0; i <= leaves; i++) {
    test = random_test();
    if (!bst_grow_leaf(root, test, test_compare)) {
      printf("[DUPLICATE] Couldn't add test struct with key '%s'\n", test->key);
      teardown_test(test);
    }
  };
  test = create_test("Let's add one at the end.");
  bst_grow_leaf(root, test, test_compare);
  printf("[TEST] Inserted %d leaves.\n", (leaves + 5));
  printf("[COUNT] Our tree has %d leaves.\n", bst_count_leaves(root));
  test = bst_get_from_tree(root, "Let's add one at the end.", test_compare_key);
  printf("[GET] We found leaf with key \"Let's add one at the end.\" at address %p.\n", test);
  test = bst_get_from_tree(root, "Hopefully this doesn't exist", test_compare_key);
  printf("[GET] We found leaf with key \"Hopefully this doesn't exist\" at address %p.\n", test);
  bst_for_each(root, printTest);
  bst_dig_up_tree(root, teardown_test);
  return 0;
};