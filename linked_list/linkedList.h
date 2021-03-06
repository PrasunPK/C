typedef struct e {
  void * value;
  struct e * next;
} Element;

typedef struct {
  Element *first;
  Element *last;
  int length;
} LinkedList;

typedef void (*ElementProcessor)(void *);

typedef int MatchFunc(void *, void *);

typedef void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

typedef void* Reducer(void* hint, void* previousItem, void* item);


LinkedList createList(void);
int add_to_list(LinkedList *, void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
void forEach(LinkedList, ElementProcessor e);
void * getElementAt(LinkedList, int );
int indexOf(LinkedList list, void * item);
void * deleteElementAt(LinkedList *, int);
int asArray(LinkedList, void **, int maxElements);
LinkedList  filter(LinkedList, MatchFunc, void * );
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, ConvertFunc, void * );
void * reduce(LinkedList, Reducer, void *hint, void *initialValue);
