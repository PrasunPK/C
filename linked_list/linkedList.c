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

void forEach(LinkedList list,ElementProcessor e){
  Element * ele = (Element *)list.first; 
  while(ele != NULL){
    
    e(ele->value);
    ele = ele->next;
  }
}

void * getElementAt(LinkedList list, int position){
  Element * ele = (Element *)list.first; 
  int count = 0;
  while(ele != NULL){
    if(count == position){
      return ele->value;
    }
    count++;
    ele = ele->next; 
  }
  return NULL;
}

int indexOf(LinkedList list, void * item){
  Element * ele = (Element *)list.first; 
  int index = 0;
  while(ele != NULL){
    if(ele->value == item)
      return index;
    ele = ele->next;
    index++;
  }
  return -1;
}

void * deleteElementAt(LinkedList *list, int position){
  Element * node = (Element *)list->first;
  Element * previous, *prev;
  int index = 0;
  while(node != NULL){
    previous = node;
    if(index == (position-1))
        prev = node;  

    if(index == position){
      if(position == 0){
        list->first = list->first->next;
        list->length--;
        return node->value;
      }
      if(position == (list->length-1)){
        previous->next = NULL;
        list->length--;
        return node->value;
      }
      prev->next = node->next;
      list->length--;
      return node->value;
    }
    index++;
    node = node->next;
  }
  return NULL;
}

int asArray(LinkedList list, void ** array, int maxElements){
  Element * ele = (Element *)list.first;
  int index = 0;
  while(ele != NULL && (index <= maxElements)){
    *array = ele->value;
    ele = ele->next;
    array++;
    index++;
  }
  return index;
}

LinkedList filter(LinkedList list, MatchFunc operate, void * hint){
  LinkedList new_list = createList();
  Element * node = (Element *)list.first;
  while(node != NULL){
    if(operate(node->value, hint) == 0){
      add_to_list(&new_list,node->value);
    }
    node = node->next;
  }
  return new_list;
}

void insert_in_list(LinkedList *new_list, void *item){
  Element *item_to_insert = (Element *)malloc(sizeof(Element));
  item_to_insert->value = item;
  if(new_list->first == NULL ){
    item_to_insert->next = NULL;
    new_list->first = item_to_insert;
    new_list->last = item_to_insert;
    new_list->length++; 
  }
  else{
    item_to_insert->next = new_list->first;
    new_list->first = item_to_insert;
    new_list->length++;
  }
}

LinkedList reverse(LinkedList list){
  LinkedList list_to_add = createList();
  Element *node = (Element *)list.first;
  while(node != NULL){
    insert_in_list(&list_to_add, node->value);
    node = node->next;
  } 
  return list_to_add;
}
