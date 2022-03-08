/**
 * @file linked_list_node.c
 * @author Goutham Krishna K V (gauthamkrishna9991@live.com)
 * @brief Linked List Node
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022
 *
 */

// IMPORT HEADER

#include "linked_list_node.h"

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

void linked_list_node_destroy(linked_list_node *const node) { free(node); }
