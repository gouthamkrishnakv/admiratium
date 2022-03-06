#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "linked_list.h"
#include "linked_list_node.h"

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
