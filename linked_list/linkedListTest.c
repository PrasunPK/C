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

void increment(void *item){
  *(int *)item = *(int *)item + 1;
}

void traverse(LinkedList list){
  Element * ele = (Element *)list.first;
  int count = 1;
  while(ele != NULL){
    assert(*(int *)ele->value == (10+count));
    ele = ele->next;
    count++;
  }
}

void test_forEach(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);

  forEach(list, &increment);
  printf("Elements are incremented in a link list\n");
  traverse(list);
}

void test_getElementAt(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);

  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 'P';
  length = add_to_list(&list, item3);


  int element = *(int *)getElementAt(list, 1);
  int element1 = *(int *)getElementAt(list, 2);
  char element2 = *(char *)getElementAt(list, 3);
  
  assert(element == 11);
  assert(element1 == 12);
  assert(element2 == 'P');
  printf("Element has been found at second position\n");
}

void test_indexOf(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 'P';
  length = add_to_list(&list, item3);
  
  int item_to_find = 12;
  int index = indexOf(list, item2); 
  
  assert(index == 2);
  printf("Item is found and returned the index correctly\n"); 
  
  index = indexOf(list, &item_to_find);
  assert(index == -1); 
  printf("returns -1 if item is not found\n");
}

void test_deleteElementAt(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 'P';
  length = add_to_list(&list, item3);
  
  int index = 0; 
  int * deleted_item = deleteElementAt(&list,index);

  assert(*(int *)deleted_item == 10);
  printf("Item has been deleted and returned\n");
  
  int item_to_find = 10;
  assert(indexOf(list, item) == -1); 
  printf("deleted item can not be found\n");
  
  index = 2; 
  char * deleted_item_1 = deleteElementAt(&list,index);

  assert(*(char *)deleted_item_1 == 'P');
  assert(list.length == 2);
  printf("Last item has been deleted and returned\n");
  
  assert(indexOf(list, &item3) == -1); 
  printf("deleted item can not be found\n");

}

void test_deleteElementAt_deleting_from_middle(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 'P';
  length = add_to_list(&list, item3);
  
  int index = 2;
  int * deleted_item = deleteElementAt(&list,index);
  assert(*(int *)deleted_item == 12);
  assert(list.length == 3);
  printf("Item has been deleted from the middle and returned\n");

  assert(indexOf(list, item2) == -1); 
  printf("deleted item can not be found\n");
}

void traverseArray(LinkedList list, void **array, int maxItems){
  Element * node = (Element *)list.first;
  for(int i = 0;i <maxItems; i++){
    assert(*(int *)node->value == *(int *)array[i]);
    node = node->next;
  }
  printf("All the elements are same as the linked list\n");
}

void test_asArray(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 13;
  length = add_to_list(&list, item3);
  
  void *array[4];
  int maxItems = 4;

  int no_of_elements = asArray(list, array,maxItems);
  assert(no_of_elements == 4);
  traverseArray(list, array, maxItems);
  printf("Items are inserted into the given array\n");
}

int isEven(void * item, void * hint){
  return *(int *)item % 2 ;
}

void test_filter(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 13;
  length = add_to_list(&list, item3);
  
  LinkedList filtered_list = filter(list, isEven, NULL);
  
  assert(filtered_list.length == 2);
  printf("List has been filtered and has two items in it\n");
  
  int element = *(int *)getElementAt(filtered_list, 0);
  int element1 = *(int *)getElementAt(filtered_list, 1);

  assert(element == 10);
  assert(element1 == 12);
  printf("Two items are there in the filtered list\n");
}

void test_reverse(){
  LinkedList list = createList();
  void *item = (int *)malloc(sizeof(int));
  *(int *)item = 10;
  int length = add_to_list(&list, item);
  void *item1 = (int *)malloc(sizeof(int));
  *(int *)item1 = 11;
  length = add_to_list(&list, item1);
  void *item2 = (int *)malloc(sizeof(int));
  *(int *)item2 = 12;
  length = add_to_list(&list, item2);
  void *item3 = (char *)malloc(sizeof(char));
  *(char *)item3 = 13;
  length = add_to_list(&list, item3);
   
  LinkedList reversed_list = reverse(list);
  
  assert(reversed_list.length == 4);
  assert(*(int *)(reversed_list.first->value) == 13);
  assert(*(int *)(reversed_list.last->value) == 10);
  int element = *(int *)getElementAt(reversed_list, 1);
  int element1 = *(int *)getElementAt(reversed_list, 2);

  assert(element == 12);
  assert(element1 == 11);
  
  printf("Given linked list has been reversed\n");
}

