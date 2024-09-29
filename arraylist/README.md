# Generic Dynamic Array in C

This project demonstrates the implementation of a generic dynamic array (similar to Java's `ArrayList`) in C. It focuses on low-level data structures, memory management, and dynamic resizing of arrays.

## Features

- Dynamic resizing of arrays
- Generic support for various data types
- Efficient memory allocation and management

## Files

- `arraylist.h`: Header file for the dynamic array, containing function declarations and data structure definitions.
- `arraylist.c`: Implementation of the dynamic array functions.
- `main.c`: Test file to demonstrate the usage of the dynamic array.

## Prerequisites

- C compiler (GCC or Clang)
- Basic understanding of data structures and pointers in C

## Compilation

To compile the project, use the following command:

```bash
gcc -o arraylist main.c arraylist.c
```

## Running the Program

Once compiled, run the executable:

```bash
./arraylist
```

## Checklist

### 1. Create the project structure

- [x] Create the main project directory.
- [x] Add the files `arraylist.h`, `arraylist.c`, and `main.c`.

### 2. Design the Dynamic Array Structure

- [x] Define the dynamic array structure in `arraylist.h`.
- [x] Declare necessary function prototypes (e.g., `init`, `add`, `remove`, `is_empty`).

### 3. Implement Array Initialization (`arraylist.c`)

- [x] Implement the `initArrayList()` function to initialize the array with an initial capacity.
- [x] Allocate memory dynamically using `malloc`.

### 4. Add Elements to the Array

- [x] Implement the `addElement()` function to add elements to the array.
- [x] Ensure dynamic resizing when the array reaches its capacity.

### 5. Remove Elements from the Array

- [ ] Implement the `removeElement()` function to remove elements.
- [ ] Handle shrinking the array size if necessary.

### 6. Implement Memory Management

- [ ] Implement a `freeArrayList()` function to free the dynamically allocated memory.
- [ ] Ensure all memory is freed properly to avoid memory leaks.

### 7. Test the Array Implementation (`main.c`)

- [ ] Write test cases to demonstrate adding, removing, and resizing the array.
- [ ] Test with various data types (int, float, etc.).
- [ ] Ensure the array handles edge cases (e.g., adding beyond capacity, removing from an empty array).

### 8. Document the Code

- [ ] Add comments explaining each function and its purpose.
- [ ] Ensure the README includes compilation and usage instructions.

### 9. Final Testing and Review

- [ ] Run the program and verify correct behavior.
- [ ] Review for any remaining memory management issues (use `valgrind` to check for memory leaks).
