/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#include "linked-list.h"

#include <stdlib.h>
#include <string.h>

struct sll_node* new_sll_node(void* ptr) {
  struct sll_node* output = malloc(sizeof(struct sll_node));
  memset(output, 0, sizeof(struct sll_node));
  output->ptr = ptr;
  return output;
};

struct sll_node* sll_append(struct sll_node* node, void* ptr) {
  while (node->next)
    node = node->next;
  node->next = new_sll_node(ptr);
  return node->next;
};

int sll_for_each(struct sll_node* node, int callback(void*)) {
  if (!callback)
    return 1;
  int res = 0;
  while (node) {
    res = callback(node->ptr);
    if (res)
      return res;
    node = node->next;
  };
  return res;
};

void sll_teardown(struct sll_node* node, void teardown_ptr(void*)) {
  while (node) {
    if (teardown_ptr)
      teardown_ptr(node->ptr);
    struct sll_node* next = node->next;
    free(node);
    node = next;
  };
};

unsigned int sll_count_list(struct sll_node* node) {
  unsigned int i = 0;
  while (node) {
    i++;
    node = node->next;
  };
  return i;
};

struct sll_node* sll_remove_node(struct sll_node* front, struct sll_node* node) {
  if (front == node) {
    struct sll_node* output = node->next;
    free(node);
    return output;
  };
  struct sll_node* n = front;
  while (n->next) {
    if (n->next == node) {
      n->next = node->next;
      free(node);
      return front;
    };
    n = n->next;
  };
  return front;
};
