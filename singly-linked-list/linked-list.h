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

typedef struct {
  struct sll_node* first;
  struct sll_node* last;
  unsigned int count;
} singly_linked_list;

/** @summary Allocates a new singly linked list
 * @param ptr The pointer for the first element in case it's NULL no elements are added
 * @return A newly allocated singly linked list with 1 item
 */
singly_linked_list* new_singly_linked_list(void* ptr);

#define new_empty_singly_linked_list() new_singly_linked_list(NULL)

/** @summary Appends a pointer to the end of your linked list
 * @param ssl The singly linked list to append our element to
 * @param ptr The actual pointer to add to our list
 * @return 1 if appended succesfully, 0 otherwise
 */
int sll_append(singly_linked_list* sll, void* ptr);

/** @summary For each loop made easy
 * @param sll The singly linked list to loop through
 * @param callback The function to call for each pointer. Should return 0, non-zero will stop the for each loop
 * @return Returns the result from the callback function
 */
int sll_for_each(singly_linked_list* sll, int callback(void*));

/** @summary Quickly count the linked list
 * @param sll The singly linked list to count
 * @return Amount of elements in the list.
 */
unsigned int sll_count_list(singly_linked_list* sll);

/** @summary Remove the item at position x
 * @param sll The singly list to remove this item from
 * @param x Which item to remove
 * @param teardown_ptr The function pointer to execute to destroy user data
 * @return 1 if succesfully removed, 0 otherwise
 */
int sll_remove_item_at(singly_linked_list* sll, unsigned int x, void teardown_ptr(void*));

/** @summary Simply remove this node from our list
 * @param sll The singly linked list to remove this item from
 * @param ptr The item to remove from our singly linked list
 * @param teardown_ptr The function to execute to destroy our user data
 * @return A possible new begin node for the list.
 */
int sll_remove_item(singly_linked_list* sll, void* ptr, void teardown_ptr(void*));

/** @summary Similar to sll_get_node_at but returns the user pointer
 * @param sll The singly linked list to get our item from
 * @param item Which item do we want
 * @return The user data from this location.
 */
void* sll_get_item_at(singly_linked_list* sll, unsigned int item);

/** @summary Teardown the entire list
 * @param sll The singly linked list to tear down
 * @param teardown_ptr The function to execute to destroy our user data.
 */
void sll_teardown(singly_linked_list* sll, void teardown_ptr(void*));

#endif //_SINGLY_LINKED_LIST
