#include <stdlib.h>
#include "array_utils.h"

int areEqual(ArrayUtil a, ArrayUtil b){
  char *list_of_a = (char *)a.base;
  char *list_of_b = (char *)b.base;
  if((a.typeSize == b.typeSize) && (a.length == b.length)){
    for(int i = 0; i < a.length; i++){
      if(list_of_a[i] != list_of_b[i])
        return 0;
    }
    return 1;
  }
  return 0;
}

ArrayUtil create(int typeSize, int length){
  ArrayUtil array_util;
  array_util.base = calloc(length, typeSize);
  array_util.typeSize = typeSize;
  array_util.length = length;

  return  array_util;
}

ArrayUtil resize(ArrayUtil util, int length){
  int total_byte = util.typeSize * util.length;
  util.base = realloc(util.base, total_byte) ;
  return util;
}
