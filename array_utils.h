typedef struct {
  void *base;
  int typeSize;
  int length;
} ArrayUtil;

typedef int MatchFunc(void *, void *);

int areEqual(ArrayUtil , ArrayUtil );
ArrayUtil create(int , int);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil util, void *element);
void dispose(ArrayUtil);
void * findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void * findLast(ArrayUtil util, MatchFunc* match, void* hint);
int count(ArrayUtil util, MatchFunc* match, void *hint);
