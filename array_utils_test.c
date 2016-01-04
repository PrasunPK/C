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

int main(){
  test_areEqual_when_they_are_actually_Equal();
  test_areEqual_when_they_are_not_equal();
  return 0;
}
