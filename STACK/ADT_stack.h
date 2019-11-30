#ifndef ADT_STACK
#define ADT_STACK
// 노드 선언
typedef struct node{
    void* data_ptr;
    struct node* link;
} STACK_NODE;

typedef struct {
    int count;
    STACK_NODE* top;
} STACK;

//함수 선언 
STACK* create_stack();
bool push(STACK* stack, void* in);
void* pop(STACK* stack);

#endif
