#include "arraylist.h"
#include <stdio.h>
#include <strings.h>
#include <time.h>

bool resize(Array *array);

Array *init_arraylist(size_t element_size) {
  Array *array = malloc(sizeof(Array));
  if (array == NULL) {
    return NULL;
  }
  array->capacity = 10;
  array->element_size = element_size;
  array->size = 0;
  array->data = malloc(array->capacity * array->element_size);
  if (array->data == NULL) {
    return NULL;
  }
  return array;
}

void add(Array *array, const void *data) {
  if (array->size >= array->capacity) {
    bool is_resize = resize(array);
    if (!is_resize) {
      return;
    }
  }
  memcpy((char *)array->data + (array->size * array->element_size), data,
         array->element_size);
  array->size++;
}

void *get(const Array *array, int index) {
  if (index >= array->size) {
    printf("Error: Array Out of Bound Exceptions %d and size is %zu\n", index,
           array->size);
    exit(EXIT_FAILURE);
  }
  return (char *)array->data + (index * array->element_size);
}

bool resize(Array *array) {
  if (array->size < array->capacity) {
    return false;
  }

  array->capacity *= 2;
  Array *newData = realloc(array->data, array->element_size * array->capacity);
  if (newData == NULL) {
    return NULL;
  }
  array->data = newData;
  return true;
}

int size(const Array *array) { return array->size; }

bool is_empty(const Array *array) { return array->size == 0; }
