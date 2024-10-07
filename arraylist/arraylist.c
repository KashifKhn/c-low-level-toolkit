#include "arraylist.h"
#include <stdbool.h>
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
    free(array);
    return NULL;
  }
  return array;
}

void add_element(Array *array, const void *data) {
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

void *get_element(const Array *array, int index) {
  if (index < 0 || index >= array->size) {
    printf("Error: Array Out of Bound Exceptions %d and size is %zu\n", index,
           array->size);
    exit(EXIT_FAILURE);
  }
  return (char *)array->data + (index * array->element_size);
}

void *remove_element(Array *array, int index) {
  if (index < 0 || index >= array->size) {
    printf("Error: Array Out of Bound Exceptions %d and size is %zu\n", index,
           array->size);
    exit(EXIT_FAILURE);
  }

  void *value = malloc(array->element_size);
  if (!value) {
    printf("Error: Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  memcpy(value, get_element(array, index), array->element_size);

  memmove((char *)array->data + index * array->element_size,
          (char *)array->data + (index + 1) * array->element_size,
          (array->size - index - 1) * array->element_size);

  array->size--;

  // NOTE: the caller is responsible for freeing the returned memory after
  // removing an element.
  // NOTE: Caller must free this memory
  return value;
}

void free_arraylist(Array *array) {
  // NOTE: The caller still needs to set their pointer to NULL after calling
  // free_arraylist to avoid using a dangling pointer.
  if (array == NULL) {
    return;
  }
  free(array->data);
  array->data = NULL;
  free(array);
  array = NULL;
}

bool resize(Array *array) {
  if (array->size < array->capacity) {
    return false;
  }

  array->capacity *= 2;
  void *newData = realloc(array->data, array->element_size * array->capacity);
  if (newData == NULL) {
    return false;
  }
  array->data = newData;
  return true;
}

int size(const Array *array) { return array->size; }

bool is_empty(const Array *array) { return array->size == 0; }
