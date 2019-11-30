#ifndef ADT_LLIST
#define ADT_LLIST

typedef struct lnode{
  void* data_ptr;
  struct lnode* next;
}NODE;

typedef struct {
  int count;
  int (*cmp_func)(void* a, void*b);
  void (*prt_func)(void* x);
  NODE* front;
  NODE* rear;
  NODE* pos;
}LLIST;

//LLIST* create_list();
LLIST* create_list(int (*cmp_func)(void* a,void* b),void (*prt_func)(void* x));
bool add_node_at(LLIST* list,unsigned int index, void* in);
bool del_node_at(LLIST* list,unsigned int index);
void* get_data_at(LLIST* list, unsigned int index);
void destroy_list(LLIST* list);
int find_data(LLIST* list , void* search_data);


#endif
