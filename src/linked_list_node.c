// IMPLTN: Linked List Node

// Import Header

#include "linked_list_node.h"

// Create: Defn

linked_list_node *linked_list_node_create(int64_t ele, linked_list_node *next) {
  linked_list_node *new_node =
      (linked_list_node *)malloc(sizeof(linked_list_node));
  // Null-pointer guard
  if (new_node == NULL)
    return NULL;
  // Assign parameter values
  new_node->ele = ele;
  new_node->next = next;
  return new_node;
}

// Destroy: Defn

void linked_list_node_destroy(linked_list_node *const node) { free(node); }
