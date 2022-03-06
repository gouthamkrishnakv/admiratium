

#include "linked_list.h"

linked_list *linked_list_create() {
  linked_list *new_list = (linked_list *)malloc(sizeof(linked_list));
  // Null-pointer guard
  if (new_list == NULL)
    return NULL;
  // Assign empty values
  new_list->head = NULL;
  new_list->length = 0;
  return new_list;
}

void linked_list_destroy(linked_list *const list) {
  // Null-pointer guard
  if (list == NULL)
    return;
  // Node traversal pointers
  linked_list_node *current = list->head, *next_node = NULL;
  // While current node is not null:
  while (current != NULL) {
    // destroy the current node and initialize it with the next node
    next_node = current->next;
    linked_list_node_destroy(current);
    current = next_node;
  }
  // destroy the list allocation
  free(list);
}

bool linked_list_insert_to_head(linked_list *const list, int64_t ele) {
  // Create a new node whose 'next' element is the old node
  linked_list_node *new_node = linked_list_node_create(ele, list->head);
  // out-of-memory guard
  if (new_node == NULL)
    return false;
  // Assign new_node to head
  list->head = new_node;
  return true;
}

int64_t linked_list_remove_from_head(linked_list *const list) {
  // Null-pointer guards
  if (list == NULL || list->head == NULL)
    return INT64_MIN;
  // Copy return value from head
  int64_t ele_in_head = list->head->ele;
  // Put the next element as the head element
  list->head = list->head->next;
  // Return the head element
  return ele_in_head;
}

void linked_list_print(const linked_list *const list) {
  if (list == NULL || list->head == NULL) {
    printf("NULL LIST");
  } else {
    linked_list_node *current = list->head;
    while (current != NULL) {
      printf("%ld ", current->ele);
      current = current->next;
    }
  }
  printf("\n");
}
