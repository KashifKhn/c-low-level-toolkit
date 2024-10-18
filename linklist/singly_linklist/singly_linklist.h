#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

Node *init_list(size_t elementType);

void add_at_start(void *data);

void add_at_end(void *data);

void *remove_at_end(void *data);

void *remvoe_at_start(void *data);

void *find_node(void *data);

bool is_empty();

#endif // LINKLIST_H
