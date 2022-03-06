// HEADER: Linked List

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

// Linked List Structure

typedef struct linked_list {
  linked_list_node *head;
  size_t length;
} linked_list;

linked_list *linked_list_create();

void linked_list_destroy(linked_list *const list);

bool linked_list_insert_to_head(linked_list *const list, int64_t ele);

int64_t linked_list_remove_from_head(linked_list *const list);

void linked_list_print(const linked_list *const list);

#endif
