#include <stdlib.h>
#include "array_utils.h"

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


