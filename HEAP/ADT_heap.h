

typedef struct{
  int last;
  int size;
  int* array;
  int max_size;
} HEAP;


HEAP* create_heap(int max);

bool insertHeap(HEAP* heap, int last, int data);

int* reheapUp(HEAP* heap, int new_node)
