/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#ifndef _SINGLY_LINKED_LIST
#define _SINGLY_LINKED_LIST

struct sll_node {
  void* ptr;
  struct sll_node* next;
};

struct sll_node* new_sll_node();

struct sll_node* sll_append(struct sll_node* node, void* ptr);

int sll_for_each(struct sll_node* node, int callback(void*));

unsigned int sll_count_list(struct sll_node* node);

struct sll_node* sll_remove_node(struct sll_node* front, struct sll_node* node);

void sll_teardown(struct sll_node* node, void teardown_ptr(void*));

#endif //_SINGLY_LINKED_LIST
