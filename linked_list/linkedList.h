typedef struct e {
  int value;
  struct e * next;
} Element;

typedef struct {
  Element *first;
  Element *last;
  int length;
} LinkedList;

LinkedList createList(void);
int add_to_list(LinkedList *, void *);

