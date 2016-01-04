#include <stdio.h>
#include <assert.h>
#include "array_utils.h"

void test_areEqual_when_they_are_actually_Equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 5);
  assert(areEqual(a,b) == 0);
  printf("Two array utils are equal\n");
}

void test_areEqual_when_they_are_not_equal(){
  ArrayUtil a = create(4, 5);
  ArrayUtil b = create(4, 7);
  assert(areEqual(a,b) == 1);
  printf("Two array utils are not equal\n");
}

void test_create(){
  ArrayUtil a = create(4, 5);

  assert(a.length == 5);
  assert(a.typeSize == 4);
  printf("create creates an array util with size 5 and typeSize 4 \n");
}

void test_resize(){
  ArrayUtil a = create(4, 5);
  ArrayUtil new_a = resize(a, 10);

  assert(new_a.length == 10);
  printf("Array size is resized to greater length\n");

  ArrayUtil new_util = resize(a, 3);
  assert(new_util.length == 3);
  printf("Array size is resized to smaller length\n");
}

int main(){
  test_areEqual_when_they_are_actually_Equal();
  test_areEqual_when_they_are_not_equal();
  test_create();
  test_resize();
  return 0;
}
