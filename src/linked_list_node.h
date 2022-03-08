/**
 * @file linked_list_node.h
 * @author Goutham Krishna K V (gauthamkrishna9991@live.com)
 * @brief Header: Linked List Node
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022 Goutham Krishna K V
 *
 */

// Header Guard

#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H

// IMPORTS: Libraries

#include <stdint.h>
#include <stdlib.h>

// Structure

/**
 * @brief Linked-List Node
 */
typedef struct linked_list_node {
  int64_t ele;
  struct linked_list_node *next;
} linked_list_node;

// Methods

/**
 * @brief Create linked_list_node object from given paramaters
 *
 * @param ele the node value to hold
 * @param next the next element to be held
 * @return linked_list_node* Created linked-list node object
 */
linked_list_node *linked_list_node_create(int64_t ele, linked_list_node *next);

/**
 * @brief Destroy created linked_list_node.
 *
 * @param node node to destroy
 */
void linked_list_node_destroy(linked_list_node *const node);

#endif
