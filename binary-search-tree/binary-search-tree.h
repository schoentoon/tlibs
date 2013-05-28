/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

struct bst_leaf {
  void* ptr;
  struct bst_leaf* left;
  struct bst_leaf* right;
};

typedef struct bst_leaf bst_roots;
typedef int bst_comparator(void* ptr1, void* ptr2);

bst_roots* new_bst_tree(void* ptr);

struct bst_leaf** bst_tree_search(struct bst_leaf** leaf, void* ptr, bst_comparator comparator);

int bst_new_leaf(bst_roots* root, void* ptr, bst_comparator comparator);

#endif //_BINARY_SEARCH_TREE_H
