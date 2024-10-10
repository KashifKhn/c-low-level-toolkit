# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Target executable
TARGET = main

# Source files
SRCS = main.c arraylist.c

# Default target to build the program
all: $(TARGET)

# Build the executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Run Valgrind for memory check
valgrind: $(TARGET)
	 valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
         ./main

# Clean up the executable
clean:
	rm -f $(TARGET)

.PHONY: all clean val
