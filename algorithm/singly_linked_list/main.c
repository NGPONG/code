#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

#include "singly_list.h"

void printer_int(node_t *current) {
  printf("node address = %p, data address = %p, Data value = %d\n", current, current->data, *(int *)current->data);
}

int main(void) {
  list_t *list = create();
  for (int i = 0; i < 100; i++) {

    int *a = malloc(sizeof(int));
    if (a == NULL) {

      perror("heap error");
      return -1;
    }
    *a = i + 1;
    add_node(list, a);
  }

  foreach_all_node(list, printer_int);

  reverse_list(list);

  foreach_all_node(list, printer_int);

  free_list(list);
  system("pause");
  return EXIT_SUCCESS;
}
