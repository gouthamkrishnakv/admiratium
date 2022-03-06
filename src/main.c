#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct linked_list_node {
  int64_t ele;
  struct linked_list_node *next;
} linked_list_node;

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

typedef struct linked_list {
  linked_list_node *head;
  size_t length;
} linked_list;

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

enum { INSERT = 1, DELETE = 2, LIST = 3, QUIT = 4 };

int main() {
  // Linked List Object
  linked_list *list = linked_list_create();
  // Command accepting string
  char *cmd = (char *)malloc(256 * sizeof(char));
  // Command Option
  int option = 0;
  // Variable to insert and delete element
  int64_t ele;
  // As long as option isn't QUIT or ERROR
  while (option != QUIT) {
    // Reset ele variable
    ele = 0;
    // Accept string Std. Input
    fgets(cmd, 255, stdin);
    // Parse command and variable (if exists)
    sscanf(cmd, "%d %ld", &option, &ele);
    // Select an option
    switch (option) {
    case INSERT:
      linked_list_insert_to_head(list, ele);
      break;
    case DELETE:
      ele = linked_list_remove_from_head(list);
      if (ele == INT64_MIN) {
        printf("EMPTY LIST\n");
      } else {
        printf("%ld\n", ele);
      }
      break;
    case LIST:
      linked_list_print(list);
      break;
    case QUIT:
      break;
    default:
      printf("ERROR!");
      option = QUIT;
    }
  }
}
