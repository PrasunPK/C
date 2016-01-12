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
  void *item = (int *)malloc(sizeof(int));
  *(int *)item=20;
  int length = add_to_list(&list, item);

  assert(list.length == 1);
  printf("One item has been added to the list\n");
  assert(*(int *)list.first->value == 20);
  assert(*(int *)list.last->value == 20);
  printf("Item 10 has been added to the first and the last of the linked list for the first insertion\n");

  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 10;

  length = add_to_list(&list, item1);
  assert(list.length == 2);
  printf("Second item has been added\n");

  assert(*(int *)list.first->value == 20);
  assert(*(int *)list.last->value == 10);

  printf("Second item has been added to the last of the list\n");
};

void test_get_first_element(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 20;

  int length = add_to_list(&list, item);
  assert(*(int *)get_first_element(list) == 20);
  
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 10;
  length = add_to_list(&list, item1);
  
  assert(*(int *)get_first_element(list) == 20);

  printf("First item is the same afetr the insertion of the first element\n");
};

void test_get_last_element(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 20;

  int length = add_to_list(&list, item);
  assert(*(int *)get_last_element(list) == 20);
  
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 10;
  length = add_to_list(&list, item1);
  
  assert(*(int *)get_last_element(list) == 10);

  printf("last item is changed afetr insertion of new element\n");

}
