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
- valgrind (if test for memory leaks)

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

## Using Make

Alternatively, you can use `make` to compile, run, and clean up the project:

### Build the project:

```bash
make
```

### Run the program:

```bash
./main
```

### Clean the project:

```bash
make clean
```

### Run Valgrind:

```bash
make valgrind
```

## Running the Valgrind Test for Memory Leaks

Once compiled, run the valgrind:

```bash

 valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test_arraylist
```

## Usage

- For detailed usage instructions, see [Usage.md](Usage.md).
- Check out the `main.c`for detail example in test.

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

- [x] Implement the `add_element()` function to add elements to the array.
- [x] Ensure dynamic resizing when the array reaches its capacity.

### 5. Get Elements from the Array

- [x] Implement the `get_element()` function to get elements.
- [x] Handle out of bound.

### 6. Remove Elements from the Array

- [x] Implement the `remove_element()` function to remove elements.
- [x] Handle shrinking the array size if necessary.

### 7. Print Elements from the Array

- [x] Implement the `print_array()` function to display elements.
- [x] Handle printing different data types using function pointers.

### 8. Implement Memory Management

- [x] Implement a `freeArrayList()` function to free the dynamically allocated memory.
- [x] Ensure all memory is freed properly to avoid memory leaks.

### 9. Test the Array Implementation (`main.c`)

- [x] Write test cases to demonstrate adding, removing, and resizing the array.
- [x] Test with various data types (int, float, etc.).
- [x] Ensure the array handles edge cases (e.g., adding beyond capacity, removing from an empty array).

### 10. Document the Code

- [x] Ensure the README includes compilation and usage instructions.

### 11. Final Testing and Review

- [x] Run the program and verify correct behavior.
- [x] Review for any remaining memory management issues (use `valgrind` to check for memory leaks).
