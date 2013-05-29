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
typedef int bst_search_for_key(void* ptr, void* key);
typedef void bst_function(void* ptr);

bst_roots* new_bst_tree(void* ptr);

void* bst_get_from_tree(bst_roots* tree, void* key, bst_search_for_key searcher);

struct bst_leaf** bst_tree_search(bst_roots* tree, void* ptr, bst_comparator comparator);

int bst_new_leaf(bst_roots* root, void* ptr, bst_comparator comparator);

unsigned int bst_count_leaves(bst_roots* root);

void bst_for_each(bst_roots* root, bst_function function);

#endif //_BINARY_SEARCH_TREE_H
