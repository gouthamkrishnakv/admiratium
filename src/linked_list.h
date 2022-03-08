/**
 * @file linked_list.h
 * @author Goutham Krishna K V (gauthamkrishna9991@live.com)
 * @brief Header: Linked List
 * @version 0.1
 * @date 2022-03-09
 *
 * @copyright Copyright (c) 2022 Goutham Krishna K V
 *
 */

// Header Guard

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// IMPORTS: Libraries

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// IMPORTS: Self

#include "linked_list_node.h"

// Structure

/**
 * @brief Linked-List
 */
typedef struct linked_list {
  linked_list_node *head;
  size_t length;
} linked_list;

/**
 * @brief Create an empty linked-list object.
 *
 * @return linked_list* created empty linked-list
 */
linked_list *linked_list_create();

/**
 * @brief Destroy the linked-list (ptr) passed in.
 *
 * @param list list to destroy
 */
void linked_list_destroy(linked_list *const list);

/**
 * @brief Insert an element to head
 *
 * This method inserts an element (of type int64_t) onto the list given.
 * @param list list to insert element into
 * @param ele element to be inserted
 * @return Status of Insertion
 */
bool linked_list_insert_to_head(linked_list *const list, int64_t ele);

/**
 * @brief Remove an element from head
 *
 * @param list list whose head from which element is to be removed from
 * @return INT_MIN on unsuccessful removal
 */
int64_t linked_list_remove_from_head(linked_list *const list);

/**
 * @brief Printing the given list
 *
 * @param list list to be printed
 */
void linked_list_print(const linked_list *const list);

#endif
