#include <stdlib.h>
#include <string.h>
#include "array_utils.h"

int areEqual(ArrayUtil a, ArrayUtil b){
  char *list_of_a = (char *)a.base;
  char *list_of_b = (char *)b.base;
  if((a.typeSize != b.typeSize) || (a.length != b.length))
    return 0;
  if(memcmp(list_of_a, list_of_b, a.typeSize) != 0)
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

ArrayUtil resize(ArrayUtil util, int length){
  int total_byte = util.typeSize * util.length;
  util.base = realloc(util.base, total_byte) ;
  return util;
}

int findIndex(ArrayUtil util, void *element){
  char *list = (char *)util.base;
  for(int i = 0; i < util.length; i++){
    if(memcmp(list, element, util.typeSize) == 0)
      return i;
    list += util.typeSize;
  }
  return -1;
}

void dispose(ArrayUtil array){
  free(array.base);
}

void * findFirst(ArrayUtil util, MatchFunc* match, void * hint){
  int *list_of_array = util.base;
  for(int i = 0; i < util.length ; i++){
    if(match(hint, &list_of_array[i]))
      return &list_of_array[i];
  }
  return NULL;
}

void * findLast(ArrayUtil util, MatchFunc* match, void * hint){
  int *list_of_array = util.base;
  for(int i = util.length-1 ; i >= 0 ; i-- ){
    if(match(hint, &list_of_array[i]))
      return &list_of_array[i];
  }
  return NULL;
}

int count(ArrayUtil util, MatchFunc* match, void *hint){
    int *list_of_array = util.base;
    int count = 0;
    for(int i = 0; i < util.length ; i++){
      if(match(hint, &list_of_array[i]))
        count++;
    }
    return count;
}


int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems){
  int count = 0;
  void *num = util.base;
  for(int i = 0; i < util.length ; i++){
    if(match(hint,num) && count < maxItems){
       destination[count] = num;
       count++;
    }
    num = num + util.typeSize;
  }
  return count;  
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
  void *source_array = source.base;
  void *destination_array = destination.base;
  for(int i = 0; i < source.length; i++){
    convert(hint, source_array,destination_array);
    source_array += source.typeSize;
    destination_array += destination.typeSize;
  }
}

void forEach(ArrayUtil util, OperationFunc* operate, void* hint){
  void *source_array = util.base;
  for(int i = 0; i < util.length; i++){
    operate(hint, source_array);
    source_array += util.typeSize;
  }
}
