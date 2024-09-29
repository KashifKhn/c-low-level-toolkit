#ifndef ARRAYLIST_H
#define ARRAYLIST_H

//
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  void *data;          // Pointer to the array of elements
  size_t element_size; // Size of each element
  size_t size;         // Current number of elements
  size_t capacity;     // Allocated capacity
} Array;

/*
 * Initialize a new generic array with the given initial capacity and element
 * size. Returns a pointer to the array on success, or NULL on failure.
 */
Array *init_arraylist(size_t element_size);

/*
 * Add an element to the array.
 * @param array: Pointer to the array.
 * @param data: Pointer to the data to be added.
 */
void add(Array *array, const void *data);

/*
 * Get an element at the specified index from the array.
 * @param array: Pointer to the array.
 * @param index: Index of the element to retrieve.
 * @return: Pointer to the element at the specified index, or NULL if the index
 * is out of bounds.
 */
void *get(const Array *array, int index);

/*
 * Remove an element at the specified index from the array.
 * @param array: Pointer to the array.
 * @param index: Index of the element to remove.
 */
void remove_element(Array *array, int index);

/*
 * Get the number of elements in the array.
 * @param array: Pointer to the array.
 * @return: The number of elements in the array.
 */
int size(const Array *array);

/*
 * Check if the array is empty.
 * @param array: Pointer to the array.
 * @return: true if the array is empty, false otherwise.
 */
bool is_empty(const Array *array);

/*
 * Free the memory allocated for the array and its elements.
 * @param array: Pointer to the array.
 */
void free_arraylist(Array *array);

#endif // ARRAYLIST_H
