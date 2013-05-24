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

/** @summary Allocates a new begin node
 * @param ptr The pointer for the first element
 * @return A newly allocated begin node
 */
struct sll_node* new_sll_node(void* ptr);

/** @summary Appends a pointer to the end of your linked list
 * @param node A node from the linked list, for best performance pass the last one
 * @param ptr The actual pointer to add to our list
 * @return The newly added node.
 */
struct sll_node* sll_append(struct sll_node* node, void* ptr);

/** @summary For each loop made easy
 * @param node The begin node of the list
 * @param callback The function to call for each pointer. Should return 0, non-zero will stop the for each loop
 * @return Returns the result from the callback function
 */
int sll_for_each(struct sll_node* node, int callback(void*));

/** @summary Quickly count the linked list
 * @param node The begin node of the list
 * @return Amount of elements in the list.
 */
unsigned int sll_count_list(struct sll_node* node);

/** @summary Remove the item at position x
 * @param front The begin node of the list
 * @param x Which item to remove
 * @param teardown_ptr The function pointer to execute to destroy user data
 * @return A possible new begin node for the list.
 */
struct sll_node* sll_remove_item(struct sll_node* front, unsigned int x, void teardown_ptr(void*));

/** @summary Simply remove this node from our list
 * @param front The begin node of the list
 * @param node The node to take out of the list
 * @param teardown_ptr The function to execute to destroy our user data
 * @return A possible new begin node for the list.
 */
struct sll_node* sll_remove_node(struct sll_node* front, struct sll_node* node, void teardown_ptr(void*));

/** @summary Get the xth node of our list
 * @param front The begin node of the list.
 * @param item Which item do we want
 * @return The node at location item or NULL if item is bigger than our list
 */
struct sll_node* sll_get_node_at(struct sll_node* front, unsigned int item);

/** @summary Similar to sll_get_node_at but returns the user pointer
 * @param front The begin node of the list.
 * @param item Which item do we want
 * @return The user data from this location.
 */
void* sll_get_item_at(struct sll_node* front, unsigned int item);

/** @summary Teardown the entire list
 * @param front The begin node of the list
 * @param teardown_ptr The function to execute to destroy our user data.
 */
void sll_teardown(struct sll_node* front, void teardown_ptr(void*));

#endif //_SINGLY_LINKED_LIST
