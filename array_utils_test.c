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

int main(){
  test_areEqual_when_they_are_actually_Equal();
  test_areEqual_when_they_are_not_equal();
  test_create();
  test_resize();
  test_findIndex();
  return 0;
}
