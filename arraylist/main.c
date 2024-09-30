#include "arraylist.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  Array *arr = init_arraylist(sizeof(int));
  assert(arr != NULL);

  int value = 0;

  for (int i = 0; i < 10; i++) {
    value = i * 10;
    add(arr, &value);
    assert(size(arr) == i + 1);
    assert(*(int *)get(arr, i) == value);
  }

  assert(arr->capacity == 10);
  for (int i = 10; i < 20; i++) {
    value = i * 10;
    add(arr, &value);
    assert(size(arr) == i + 1);
    assert(*(int *)get(arr, i) == value);
  }

  assert(*(int *)get(arr, 19) == 190);

  assert(arr->capacity == 20);
  assert(size(arr) == 20);

  printf("All Test are passed");
}
