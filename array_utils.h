typedef struct {
  void *base;
  int typeSize;
  int length;
} ArrayUtil;


int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil create(int length, int typeSize);
