// HEADER: Linked List Node

// Header Guard

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

// IMPORTS: Libraries

#include <stdint.h>
#include <stdlib.h>

// Linked List Node Structure

typedef struct linked_list_node {
  int64_t ele;
  struct linked_list_node *next;
} linked_list_node;

// Create

linked_list_node *linked_list_node_create(int64_t ele, linked_list_node *next);

// Destroy

void linked_list_node_destroy(linked_list_node *const node);

#endif
