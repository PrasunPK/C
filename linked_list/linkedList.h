typedef struct e {
  void * value;
  struct e * next;
} Element;

typedef struct {
  Element *first;
  Element *last;
  int length;
} LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *, void *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
