/* * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Toon Schoenmakers <nighteyes1993@gmail.com>
 * wrote this file. As long as you retain this notice you can do whatever you
 * want with this stuff. If we meet some day, and you think this stuff is worth
 * it, you can buy us a beer in return.
 * -----------------------------------------------------------------------------
 */

#include "binary-search-tree.h"

#include <stdlib.h>
#include <string.h>

bst_roots* new_bst_tree(void* ptr) {
  bst_roots* output = malloc(sizeof(bst_roots));
  memset(output, 0, sizeof(bst_roots));
  output->ptr = ptr;
  return output;
};

struct bst_leaf** bst_tree_search(struct bst_leaf** leaf, void* ptr, bst_comparator comparator) {
  while (*leaf) {
    int cmp_res = comparator((*leaf)->ptr, ptr);
    if (cmp_res < 0)
      leaf = &(*leaf)->left;
    else if (cmp_res > 0)
      leaf = &(*leaf)->right;
    else
      return leaf;
  }
  return leaf;
};

int bst_new_leaf(bst_roots* root, void* ptr, bst_comparator comparator) {
  if (!comparator)
    return -1;
  struct bst_leaf* tmp_leaf = malloc(sizeof(struct bst_leaf));
  memset(tmp_leaf, 0, sizeof(struct bst_leaf));
  tmp_leaf->ptr = ptr;
  struct bst_leaf** leaf = bst_tree_search(&root, ptr, comparator);
  if (!*leaf) {
    *leaf = tmp_leaf;
    return 1;
  }
  free(tmp_leaf);
  return 0;
};