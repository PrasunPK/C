#include "linkedList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void test_creatList(){
  LinkedList list = createList();
  assert(list.length == 0);
  printf("List has been created with length zero\n");
};

void test_add_to_list(){
  LinkedList list = createList();
  int value = 10;
  int length = add_to_list(&list, &value);

  assert(length == 1);
  printf("One item has been added to the list\n");
  assert(list.first->value == 10);
  printf("Item 10 has been added to the first and the last of the linked list for the first insertion\n");
}
