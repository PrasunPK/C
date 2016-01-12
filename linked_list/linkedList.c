#include <stdlib.h>
#include "linkedList.h"

void initializeList(LinkedList *list){
  list->first = list->last = NULL;
  list->length = 0;
}

LinkedList createList(void){
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  initializeList(list);
  return *list;
}

int add_to_list(LinkedList *list, void *item){
  Element *el = (Element *)malloc(sizeof(Element));
  el->value = item;
  el->next = NULL;
  if(list->length == 0){
    list->first = el;
    list->last = el;
  }
  else{
    list->last->next = el;
    list->last = el;
  }

  list->length++;
  return list->length; 
}

void *get_first_element(LinkedList list){
    return list.first->value;
}

void *get_last_element(LinkedList list){
  return list.last->value;
}
