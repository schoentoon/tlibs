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

struct sll_node {
  void* ptr;
  struct sll_node* next;
};

struct sll_node* new_sll_node(void* ptr) {
  struct sll_node* output = malloc(sizeof(struct sll_node));
  if (!output)
    return NULL;
  memset(output, 0, sizeof(struct sll_node));
  output->ptr = ptr;
  return output;
};

singly_linked_list* new_singly_linked_list(void* ptr) {
  singly_linked_list* output = malloc(sizeof(singly_linked_list));
  memset(output, 0, sizeof(singly_linked_list));
  if (ptr) {
    output->first = new_sll_node(ptr);
    output->last = output->first;
  }
  return output;
};

int sll_append(singly_linked_list* sll, void* ptr) {
  if (sll->first) {
    sll->last->next = new_sll_node(ptr);
    if (!sll->last->next)
      return 0;
    sll->last = sll->last->next;
  } else {
    sll->first = new_sll_node(ptr);
    if (!sll->first)
      return 0;
    sll->last = sll->first;
  }
  return 1;
};

int sll_for_each(singly_linked_list* sll, int callback(void*)) {
  if (!callback)
    return 1;
  int res = 0;
  struct sll_node* node = sll->first;
  while (node) {
    res = callback(node->ptr);
    if (res)
      return res;
    node = node->next;
  };
  return res;
};

void sll_teardown(singly_linked_list* sll, void teardown_ptr(void*)) {
  struct sll_node* node = sll->first;
  while (node) {
    if (teardown_ptr)
      teardown_ptr(node->ptr);
    struct sll_node* next = node->next;
    free(node);
    node = next;
  };
  free(sll);
};

unsigned int sll_count_list(singly_linked_list* sll) {
  unsigned int i = 0;
  struct sll_node* node = sll->first;
  while (node) {
    i++;
    node = node->next;
  };
  return i;
};

int sll_remove_item_at(singly_linked_list* sll, unsigned int item, void teardown_ptr(void*)) {
  if (item == 0) {
    struct sll_node* to_remove = sll->first;
    sll->first = sll->first->next;
    if (teardown_ptr)
      teardown_ptr(to_remove->ptr);
    free(to_remove);
    return 1;
  } else {
    struct sll_node* n = sll->first;
    unsigned int i = 1;
    while (n->next) {
      if (++i == item) {
        struct sll_node* m = n->next;
        n->next = n->next->next;
        if (teardown_ptr)
          teardown_ptr(m->ptr);
        free(m);
        return 1;
      };
      n = n->next;
    };
  };
  return 0;
};

int sll_remove_item(singly_linked_list* sll, void* ptr, void teardown_ptr(void*)) {
  struct sll_node* node = sll->first;
  if (node->ptr == ptr) {
    sll->first = sll->first->next;
    if (teardown_ptr)
      teardown_ptr(node->ptr);
    free(node);
    return 1;
  };
  while (node->next) {
    if (node->next->ptr == ptr) {
      node->next = node->next;
      if (teardown_ptr)
        teardown_ptr(node->ptr);
      free(node);
      return 1;
    };
    node = node->next;
  };
  return 0;
};

void* sll_get_item_at(singly_linked_list* sll, unsigned int item) {
  unsigned int i = 0;
  struct sll_node* node = sll->first;
  while (node) {
    if (++i == item)
      return node->ptr;
    node = node->next;
  }
  return NULL;
};
