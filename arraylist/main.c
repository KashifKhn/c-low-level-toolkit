#include "arraylist.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>

void test_int();
void test_float();
void test_double();
void test_char();
void test_string();
void test_int_array();
void test_struct();
void test_double_array();

int main(int argc, char *argv[]) {
  test_int();
  test_float();
  test_double();
  test_char();
  test_string();
  test_int_array();
  test_struct();
  test_double_array();

  printf("All tests passed!\n");
  return 0;
}

void test_int() {
  printf("Testing int...\n");
  Array *int_arr = init_arraylist(sizeof(int));
  assert(int_arr != NULL);

  int value = 0;
  for (int i = 0; i < 10; i++) {
    value = i * 10;
    add_element(int_arr, &value);
    assert(size(int_arr) == i + 1);
    assert(*(int *)get_element(int_arr, i) == value);
  }

  assert(get_element(int_arr, -1) == NULL);
  assert(get_element(int_arr, 100) == NULL);

  free_arraylist(int_arr);
  printf("Int test passed!\n");
}

void test_float() {
  printf("Testing float...\n");
  Array *float_arr = init_arraylist(sizeof(float));
  assert(float_arr != NULL);

  float f = 0.0;
  for (int i = 0; i < 10; i++) {
    f = (float)i * 1.5;
    add_element(float_arr, &f);
    assert(size(float_arr) == i + 1);
    assert(*(float *)get_element(float_arr, i) == f);
  }

  assert(get_element(float_arr, -1) == NULL);
  assert(get_element(float_arr, 100) == NULL);

  free_arraylist(float_arr);
  printf("Float test passed!\n");
}

void test_double() {
  printf("Testing double...\n");
  Array *double_arr = init_arraylist(sizeof(double));
  assert(double_arr != NULL);

  double d = 0.0;
  for (int i = 0; i < 10; i++) {
    d = (double)i * 1.23456789;
    add_element(double_arr, &d);
    assert(size(double_arr) == i + 1);
    assert(*(double *)get_element(double_arr, i) == d);
  }

  assert(get_element(double_arr, -1) == NULL);
  assert(get_element(double_arr, 100) == NULL);

  free_arraylist(double_arr);
  printf("Double test passed!\n");
}

void test_char() {
  printf("Testing char...\n");
  Array *char_arr = init_arraylist(sizeof(char));
  assert(char_arr != NULL);

  char c = 'a';
  for (int i = 0; i < 26; i++) {
    c = 'a' + i;
    add_element(char_arr, &c);
    assert(size(char_arr) == i + 1);
    assert(*(char *)get_element(char_arr, i) == c);
  }

  assert(get_element(char_arr, -1) == NULL);
  assert(get_element(char_arr, 100) == NULL);

  free_arraylist(char_arr);
  printf("Char test passed!\n");
}

void test_string() {
  printf("Testing string...\n");
  Array *string_arr = init_arraylist(sizeof(char *));
  assert(string_arr != NULL);

  const char *strings[] = {"Hello", "World", "Dynamic", "Array", "Test"};
  for (int i = 0; i < 5; i++) {
    add_element(string_arr, &strings[i]);
    assert(size(string_arr) == i + 1);
    assert(strcmp(*(char **)get_element(string_arr, i), strings[i]) == 0);
  }

  assert(get_element(string_arr, -1) == NULL);
  assert(get_element(string_arr, 100) == NULL);

  free_arraylist(string_arr);
  printf("String test passed!\n");
}

typedef struct {
  int id;
  char name[20];
  double salary;
} Employee;

void test_struct() {
  printf("Testing struct...\n");
  Array *struct_arr = init_arraylist(sizeof(Employee));
  assert(struct_arr != NULL);

  Employee employees[] = {
      {1, "Alice", 50000.0}, {2, "Bob", 60000.0}, {3, "Charlie", 70000.0}};

  for (int i = 0; i < 3; i++) {
    add_element(struct_arr, &employees[i]);
    assert(size(struct_arr) == i + 1);
    Employee *e = (Employee *)get_element(struct_arr, i);
    assert(e->id == employees[i].id);
    assert(strcmp(e->name, employees[i].name) == 0);
    assert(e->salary == employees[i].salary);
  }

  assert(get_element(struct_arr, -1) == NULL);
  assert(get_element(struct_arr, 100) == NULL);

  free_arraylist(struct_arr);
  printf("Struct test passed!\n");
}

void test_int_array() {
  printf("Testing int array...\n");

  size_t inner_array_size = 5 * sizeof(int);
  Array *int_arr_arr = init_arraylist(inner_array_size);
  assert(int_arr_arr != NULL);

  int inner_array[5];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      inner_array[j] = i * 10 + j;
    }
    add_element(int_arr_arr, inner_array);
    assert(size(int_arr_arr) == i + 1);

    int *retrieved_array = (int *)get_element(int_arr_arr, i);
    for (int j = 0; j < 5; j++) {
      assert(retrieved_array[j] == inner_array[j]);
    }
  }

  assert(get_element(int_arr_arr, -1) == NULL);
  assert(get_element(int_arr_arr, 100) == NULL);

  free_arraylist(int_arr_arr);
  printf("Int array test passed!\n");
}

void test_double_array() {
  printf("Testing double array...\n");

  size_t inner_array_size = 5 * sizeof(double);
  Array *double_arr_arr = init_arraylist(inner_array_size);
  assert(double_arr_arr != NULL);

  double inner_array[5];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      inner_array[j] = i * 10.0 + j * 0.5;
    }
    add_element(double_arr_arr, inner_array);
    assert(size(double_arr_arr) == i + 1);

    double *retrieved_array = (double *)get_element(double_arr_arr, i);
    for (int j = 0; j < 5; j++) {
      assert(retrieved_array[j] == inner_array[j]);
    }
  }

  assert(get_element(double_arr_arr, -1) == NULL);
  assert(get_element(double_arr_arr, 100) == NULL);

  free_arraylist(double_arr_arr);
  printf("Double array test passed!\n");
}
