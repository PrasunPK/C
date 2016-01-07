#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_areEqual_when_they_are_actually_Equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 5);
  assert(areEqual(a,b) == 1);
  printf("Two array utils are equal\n");
  dispose(a);
  dispose(b);
}

void test_areEqual_when_they_are_not_equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 7);
  assert(areEqual(a,b) == 0);
  printf("Two array utils are not equal\n");
  dispose(a);
  dispose(b);
}

void test_create(){
  ArrayUtil a = create(4, 5);

  assert(a.length == 5);
  assert(a.typeSize == 4);
  printf("create creates an array util with size 5 and typeSize 4 \n");

  ArrayUtil util = create(4, 5);
    int * list_array = (int *)(util.base);
    list_array[0] = 10;
    list_array[1] = 20;
    list_array[2] = 30;
    list_array[3] = 40;
    list_array[4] = 50;
    assert(list_array[0] == 10);
    assert(list_array[3] == 40);
    assert(list_array[4] == 50);
    printf("Array element can be inserted and accessed\n");

    dispose(a);
    dispose(util);

}

void test_resize(){
  ArrayUtil util = create(4, 5);
  int * list_array = (int *)(util.base);
  list_array[0] = 10;
  list_array[1] = 20;
  list_array[2] = 30;
  list_array[3] = 40;
  list_array[4] = 50;

  assert(util.length == 5);
  ArrayUtil resized_util = resize(util, 7);
  assert(resized_util.length = 7);

  int * resized_list_array = (int *)(resized_util.base);
  assert(resized_list_array[4] == 50);
  assert(resized_list_array[5] == 0);
  assert(util.length == 5);

  assert(list_array[4] == 50);

  printf("Array element is not changed\n");

  dispose(util);
}

void test_findIndex(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 1;
  list_array[1] = 2;
  list_array[2] = 3;
  list_array[3] = 4;
  list_array[4] = 5;

  int x = 3;
  int y = 4;
  int z = 14;

  assert(findIndex(a, &x) == 2);
  assert(findIndex(a, &y) == 3);
  assert(findIndex(a, &z) == -1);
  printf("findindex gives the index of the present element\n");
 
  ArrayUtil b = create(4,4);
  float * list = (float *)(b.base);
  list[0] = 1.2;
  list[1] = 2.4;
  list[2] = 3.5;
  list[3] = 5.7;

  float m = 2.4;
  assert(findIndex(b, &m) == 1);

  printf("findIndex also works for floating point numbers\n");
  
  ArrayUtil c = create(1,4);
  char * list_ch = (char *)(c.base);
  list_ch[0] = 'A';
  list_ch[1] = 'B';
  list_ch[2] = 'P';
  list_ch[3] = 'F';

  char ch = 'P';
  assert(findIndex(c, &ch) == 2);

  printf("findIndex also works for characters\n");

  dispose(a);
  dispose(b);
  dispose(c);
}

int isEven(void* hint, void* item){
  int *number = (int *)(item);
  return !(*number % 2);
}

int isDivisable(void *hint, void *item){
  int *number = (int *)(item);
  int *given_hint = (int *)(hint);
  
  if(*number % *given_hint == 0)
    return 1;
  return 0; 

}

void test_findFirst(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 2;
  list_array[2] = 34;
  list_array[3] = 4;
  list_array[4] = 5;
  
  assert(*(int *)findFirst(a, &isEven, NULL) == 12);
  printf("findFirst finds the first even number of the list\n");

  int x = 3;
  assert(*(int *)findFirst(a, &isDivisable, &x) == 12);
  printf("findFirst finds the first divisable number by 3 from the list\n");
  dispose(a);
}

void test_findLast(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;
  
  assert(*(int *)findLast(a, &isEven, NULL) == 34);
  printf("findLast finds the last even number of the list\n");

  int x = 5;
  assert(*(int *)findLast(a, &isDivisable, &x) == 5);
  printf("findLast finds the last divisable number by 5 from the list\n");

  dispose(a);
}

void test_count(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;
  
  assert(count(a, &isEven, NULL) == 2);
  printf("count gives the number of the even numbers\n");

  int x = 5;
  assert(count(a, &isDivisable, &x) == 3);
  printf("count gives the number of the divisable numbers by 5\n");

  dispose(a);
}

void test_filter(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;

  ArrayUtil destination = create(4,5);
  int maxItems = 5;
  
  assert(filter(a, &isEven, NULL, destination.base, maxItems ) == 2 );
  printf("Values are being inserted\n");

  int * list = (int *)(destination.base);
  
  assert(((int **)destination.base)[0] == &list_array[0]);
  assert(((int **)destination.base)[0] == &list_array[0]);
  printf("Two arrays are equal\n");

  dispose(destination);
  dispose(a);
}

void addTwo(void * hint, void *sourceItem, void *destinationItem){
  *(int *)destinationItem =  *(int *)sourceItem + *(int *)hint ;
}

void test_map(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 12;
  list_array[1] = 25;
  list_array[2] = 34;
  list_array[3] = 45;
  list_array[4] = 5;

  ArrayUtil destination = create(4,5);
  
  int x = 2;
  map(a,destination,&addTwo,&x);
  
  int *dest_array = (int *)(destination.base);

  assert(dest_array[0] == 14); 
  assert(dest_array[1] == 27);
 
  printf("array now can be mapped with function"); 

  dispose(a);
  dispose(destination);
}

void square(void *hint, void *item){
  *(int *)item = *(int *)item * *(int *)item;
}

void test_forEach(){
  ArrayUtil a = create(4,5);
  int * list_array = (int *)(a.base);
  list_array[0] = 2;
  list_array[1] = 5;
  list_array[2] = 4;
  list_array[3] = 8;
  list_array[4] = 1;

  void * x = NULL;
  
  forEach(a, &square, &x);
  assert(list_array[0] == 4);
  assert(list_array[3] == 64);
  assert(list_array[4] == 1);

  printf("forEach can be used to operate on the array elements and change their value");
  
  dispose(a);
}
