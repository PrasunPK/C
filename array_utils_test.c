#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_areEqual_when_they_are_actually_Equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 5);
  assert(areEqual(a,b) == 1);
  printf("Two array utils are equal\n");
}

void test_areEqual_when_they_are_not_equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 7);
  assert(areEqual(a,b) == 0);
  printf("Two array utils are not equal\n");
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
}

int main(){
  test_areEqual_when_they_are_actually_Equal();
  test_areEqual_when_they_are_not_equal();
  test_create();
  test_resize();
  return 0;
}
