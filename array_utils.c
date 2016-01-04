#include <stdlib.h>
#include <stdio.h>

typedef struct {
  void *base;
  int typeSize;
  int length;
} ArrayUtil;

int areEqual(ArrayUtil a, ArrayUtil b){
  if((a.typeSize == b.typeSize) && (a.length == b.length))
    return 0;
  return 1;
}

ArrayUtil create(int typeSize, int length){
  ArrayUtil array_util;
  array_util.base = calloc(length, typeSize);
  array_util.typeSize = typeSize;
  array_util.length = length;

  return  array_util;
}

int main(){
  int length = 5, typeSize = sizeof(int);
  
  ArrayUtil a = create(typeSize, length);
  ArrayUtil b = create(typeSize, length);
  printf("Equality : %d\n",areEqual(a, b));
 
  printf("%d\n",a[0]); 
  return 0;
}
