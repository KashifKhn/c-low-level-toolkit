# Generic Singly Linked List in C

This project demonstrates the implementation of a **generic singly linked list** in C. It focuses on low-level data structures, manual memory management, and efficient manipulation of linked nodes.

## Features

- Singly linked list implementation
- Generic support for various data types using void pointers
- Efficient memory allocation and management
- Functions for inserting and deleting nodes at both the **start** and **end** of the list

## Files

- `singly_linklist.h`: Header file for the singly linked list, containing function declarations and data structure definitions.
- `singly_linklist.c`: Implementation of the singly linked list functions.
- `main.c`: Test file to demonstrate the usage of the singly linked list.

## Prerequisites

- C compiler (GCC or Clang)
- Basic understanding of pointers and memory management in C
- Valgrind (optional, for memory leak testing)

## Compilation

To compile the project, use the following command:

```bash
gcc -o singly_linklist main.c singly_linklist.c
```

## Running the Program

Once compiled, run the executable:

```bash
./singly_linklist
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

Once compiled, run valgrind to check for memory leaks:

```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./test_singly_linklist
```

## Usage

- For detailed usage instructions, see [Usage.md](Usage.md).
- Check out `main.c` for detailed examples of how the singly linked list is used in tests.

## Checklist

### 1. Create the Project Structure

- [x] Create the main project directory.
- [x] Add the files `singly_linklist.h`, `singly_linklist.c`, and `main.c`.

### 2. Design the Singly Linked List Structure

- [ ] Define the singly linked list node structure in `singly_linklist.h` (node with data and a pointer to the next node).
- [ ] Declare necessary function prototypes (e.g., `init_list`, `add_at_start`, `add_at_end`, `remove_at_start`, `remove_at_end`, `find_node`, `is_empty`).

### 3. Implement Linked List Initialization (`singly_linklist.c`)

- [ ] Implement `init_list()` to initialize an empty list with a head node.
- [ ] Allocate memory dynamically for each node using `malloc`.

### 4. Add Elements to the List

- [ ] Implement the `add_at_start()` function to add elements at the start of the list.
- [ ] Implement the `add_at_end()` function to add elements at the end of the list.
- [ ] Ensure correct memory allocation and pointer management.

### 5. Remove Elements from the List

- [ ] Implement the `remove_at_start()` function to remove the first element.
- [ ] Implement the `remove_at_end()` function to remove the last element.
- [ ] Ensure correct pointer updates and memory deallocation.

### 6. Print Elements from the List

- [ ] Implement the `print_list()` function to display the list elements.
- [ ] Handle printing different data types using function pointers or generic data handling.

### 7. Implement Memory Management

- [ ] Implement the `free_list()` function to free all dynamically allocated nodes.
- [ ] Ensure all memory is freed properly to avoid memory leaks.

### 8. Test the Linked List Implementation (`main.c`)

- [ ] Write test cases to demonstrate adding, removing, and searching nodes.
- [ ] Test with various data types (int, float, etc.).
- [ ] Handle edge cases (e.g., removing from an empty list, searching for non-existing elements).

### 9. Document the Code

- [ ] Ensure the README includes compilation and usage instructions.

### 10. Final Testing and Review

- [ ] Run the program and verify correct behavior.
- [ ] Use `valgrind` to check for memory management issues (memory leaks).
