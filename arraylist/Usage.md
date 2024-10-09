# Dynamic Array List Usage Documentation

## Overview

This document details the implementation and usage of a dynamic array in C. The dynamic array allows for efficient management of arrays of different data types, including integers, doubles, strings, characters, and user-defined structures.

## Array Structure

The `Array` structure is defined as follows:

```c
typedef struct {
    void *data;           // Pointer to the data array
    size_t element_size;  // Size of each element in bytes
    size_t size;          // Current number of elements
    size_t capacity;      // Maximum number of elements before resizing
} Array;
```

### Memory Management

The dynamic array dynamically allocates memory for elements and may resize as necessary. Users must ensure proper memory management to avoid memory leaks or invalid access.

## Function Documentation

### `Array *init_arraylist(size_t element_size)`

Initializes a new dynamic array.

- **Parameters**:
  - `element_size`: Size of each element to be stored in the array.
- **Returns**:
  - Pointer to the newly created array, or `NULL` if memory allocation fails.

#### Edge Cases:

- If `element_size` is 0, the function should return `NULL`.
- If memory allocation for the array fails, the function returns `NULL`.

### `void add_element(Array *array, const void *data)`

Adds an element to the end of the array.

- **Parameters**:
  - `array`: Pointer to the array.
  - `data`: Pointer to the data to be added.

#### Edge Cases:

- If `array` is `NULL`, the function will attempt to access a null pointer, resulting in undefined behavior.
- If the array reaches its capacity, it will trigger a resize. If resizing fails, the function does not add the element and returns silently.

### `void *get_element(const Array *array, int index)`

Retrieves an element from the array at a specific index.

- **Parameters**:
  - `array`: Pointer to the array.
  - `index`: The index of the element to retrieve.
- **Returns**:
  - Pointer to the element, or `NULL` if the index is out of bounds.

#### Edge Cases:

- If `array` is `NULL`, accessing its properties leads to undefined behavior.
- If `index` is negative or greater than or equal to `array->size`, an error message is printed, and the function returns `NULL`.

### `void *remove_element(Array *array, int index)`

Removes an element from the array at a specific index and returns it.

- **Parameters**:
  - `array`: Pointer to the array.
  - `index`: The index of the element to remove.
- **Returns**:
  - Pointer to the removed element, or `NULL` if the index is out of bounds.

#### Edge Cases:

- If `index` is negative or out of bounds, an error message is printed, and the function returns `NULL`.
- If `array` is `NULL`, the function attempts to access it, leading to undefined behavior.

### `void remove_element_free(Array *array, int index)`

Removes an element from the array at a specific index without returning it.

- **Parameters**:
  - `array`: Pointer to the array.
  - `index`: The index of the element to remove.

#### Edge Cases:

- If `index` is out of bounds, an error message is printed, and the function does not attempt to remove any element.
- If `array` is `NULL`, the function attempts to access it, leading to undefined behavior.

### `void print_array(Array *arr, void (*print_func)(void *))`

Prints all elements in the array using a specified print function.

- **Parameters**:
  - `arr`: Pointer to the array.
  - `print_func`: Function pointer for printing an element.

#### Edge Cases:

- If `arr` is `NULL`, the function will not print anything and should ideally handle this case gracefully.
- If `print_func` is `NULL`, the function will result in undefined behavior when attempting to call it.

### `void free_arraylist(Array *array)`

Frees the memory allocated for the array.

- **Parameters**:
  - `array`: Pointer to the array to be freed.

#### Edge Cases:

- If `array` is `NULL`, the function returns immediately without attempting to free memory.
- After freeing, the pointer should be set to `NULL` in the caller to avoid dangling pointers.

### `bool resize(Array *array)`

Resizes the internal data array to accommodate more elements.

- **Parameters**:

  - `array`: Pointer to the array.

- **Returns**:
  - `true` if resizing was successful, `false` otherwise.

#### Edge Cases:

- If `array` is `NULL`, the function will attempt to access it, leading to undefined behavior.
- If the resizing fails due to memory allocation failure, the function returns `false`.

### `int size(const Array *array)`

Returns the current size of the array.

- **Parameters**:

  - `array`: Pointer to the array.

- **Returns**:
  - Current number of elements in the array.

#### Edge Cases:

- If `array` is `NULL`, this will lead to undefined behavior as it attempts to access properties of a null pointer.

### `bool is_empty(const Array *array)`

Checks if the array is empty.

- **Parameters**:

  - `array`: Pointer to the array.

- **Returns**:
  - `true` if the array is empty, otherwise `false`.

#### Edge Cases:

- If `array` is `NULL`, the function will lead to undefined behavior when accessing its size.

## Example Usage

### Example 1: Integer Array

```c
#include "arraylist.h"
#include <stdio.h>

int main() {
    Array *intArray = init_arraylist(sizeof(int));
    int value;

    for (int i = 0; i < 5; i++) {
        value = i * 2;
        add_element(intArray, &value);
    }

    print_array(intArray, (void (*)(void *)) printf);
    free_arraylist(intArray);
    return 0;
}
```

### Example 2: Double Array

```c
#include "arraylist.h"
#include <stdio.h>

int main() {
    Array *doubleArray = init_arraylist(sizeof(double));
    double dValue;

    for (int i = 0; i < 5; i++) {
        dValue = (double)i / 2.0;
        add_element(doubleArray, &dValue);
    }

    print_array(doubleArray, (void (*)(void *)) printf);
    free_arraylist(doubleArray);
    return 0;
}
```

### Example 3: String Array

```c
#include "arraylist.h"
#include <stdio.h>

int main() {
    Array *stringArray = init_arraylist(sizeof(char *));
    char *strValue;

    strValue = "Hello";
    add_element(stringArray, &strValue);
    strValue = "World";
    add_element(stringArray, &strValue);

    print_array(stringArray, (void (*)(void *)) printf);
    free_arraylist(stringArray);
    return 0;
}
```

### Example 4: Character Array

```c
#include "arraylist.h"
#include <stdio.h>

int main() {
    Array *charArray = init_arraylist(sizeof(char));
    char cValue;

    for (char c = 'A'; c <= 'E'; c++) {
        add_element(charArray, &c);
    }

    print_array(charArray, (void (*)(void *)) printf);
    free_arraylist(charArray);
    return 0;
}
```

### Example 5: Struct Array

```c
#include "arraylist.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    Array *personArray = init_arraylist(sizeof(Person));
    Person pValue;

    strcpy(pValue.name, "Alice");
    pValue.age = 30;
    add_element(personArray, &pValue);

    strcpy(pValue.name, "Bob");
    pValue.age = 25;
    add_element(personArray, &pValue);

    print_array(personArray, (void (*)(void *)) printf);
    free_arraylist(personArray);
    return 0;
}
```

## Notes on Edge Cases

1. **Null Checks**: Always check if pointers are `NULL` before dereferencing them. This helps prevent segmentation faults and undefined behavior.

2. **Memory Allocation**: After calling any function that may allocate memory (like `init_arraylist` or `malloc`), ensure to check the return value to prevent accessing null pointers.

3. **Resize Logic**: The resize logic must handle cases where the resizing fails due to memory exhaustion. Implement a fallback mechanism if required.

4. **Data Consistency**: When modifying the array, such as adding or removing elements, ensure that the integrity of data is maintained.

5. **Freeing Memory**: Always free the dynamically allocated memory to avoid memory leaks. The user should set pointers to `NULL` after freeing them.

6. **Boundary Conditions**: Consider testing edge cases such as adding to a full array, removing from an empty array, and accessing out-of-bound indices.

## Conclusion

This dynamic array implementation provides a robust way to manage collections of data in C

. By handling various data types and offering functions for modification and retrieval, it serves as a versatile tool for developers. Always remember to consider edge cases and handle memory appropriately to ensure the stability of applications using this dynamic array.
