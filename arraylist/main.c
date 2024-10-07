#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  Array *arr = init_arraylist(sizeof(int));
  assert(arr != NULL);

  int value = 0;

  for (int i = 0; i < 10; i++) {
    value = i * 10;
    add_element(arr, &value);
    assert(size(arr) == i + 1);
    assert(*(int *)get_element(arr, i) == value);
  }

  assert(*(int *)remove_element(arr, 2) == 20);

  assert(arr->capacity == 10);

  free_arraylist(arr);

  printf("All Test are passed");
}
