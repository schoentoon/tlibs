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

typedef struct {
  char* key;
  int random;
} test;

test* create_test(char* key) {
  test* output = malloc(sizeof(test));
  output->key = key;
  output->random = rand();
  return output;
};

test* random_test() {
  static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  size_t len = rand() % 32;
  char* key = malloc(len + 1);
  int i;
  for (i = 0; i < len; i++)
    key[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  key[len] = '\0';
  return create_test(key);
};

int test_compare(void* ptr1, void* ptr2) {
  return strcmp(((test*) ptr1)->key, ((test*) ptr2)->key);
};

int main(int argc, char** argv) {
  srand(time(NULL));
  test* test = create_test("This is a key");
  bst_roots* root = new_bst_tree(test);
  test = create_test("This is another key");
  bst_new_leaf(root, test, test_compare);
  test = create_test("Now for some random strings");
  bst_new_leaf(root, test, test_compare);
  int leaves = rand() % 32;
  int i;
  for (i = 0; i <= leaves; i++) {
    test = random_test();
    bst_new_leaf(root, test, test_compare);
  };
  test = create_test("Let's add one at the end.");
  bst_new_leaf(root, test, test_compare);
  printf("[TEST] Inserted %d leaves.\n", (leaves + 3));
  return 0;
};