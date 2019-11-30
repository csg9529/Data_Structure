#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"ADT_llist.h"

LLIST* create_list(int (*cmp_func)(void* a,void* b),void (*prt_func)(void* x)){

  LLIST* list =(LLIST*)malloc(sizeof(LLIST));
if(list){
  list->cmp_func=cmp_func;
  list->prt_func=prt_func;
  list->count=0;
  list->front=NULL;
  list->rear=NULL;
  list->pos=NULL;

}
 return list;

}

int find_data(LLIST* list , void* search_data){
  list -> pos = list -> front;
  int cmp_result ,left ,right;
  int iter_i = 0;
  while(list->pos != NULL){

    cmp_result = (*(list->cmp_func))(list->pos->data_ptr,search_data);
    if(cmp_result == 0)
      return iter_i;

    list->pos = list->pos -> next;
    iter_i++;
  }
  return -1;
}


/*LLIST* create_list(){

  LLIST* list =(LLIST*)malloc(sizeof(LLIST));
if(list){

  list->count=0;
  list->front=NULL;
  list->rear=NULL;
  list->pos=NULL;
}
 return list;

}*/

bool add_node_at(LLIST* list,unsigned int index, void* in){
  if(index>list->count)return false;
  NODE* node_p=(NODE*)malloc(sizeof(NODE));

  if(!node_p) return false;

  node_p->data_ptr =in;
  node_p->next=NULL;

 if(list->count == 0){

   list->front = node_p;
   list->rear = node_p;
   (list->count)++;
   return true;

 }
 int iter_i=0;

 if(index == 0){

   node_p->next=list->front;
   list->front=node_p;
   (list->count)++;
   return true;
 }
 if(index == list->count){
   list->rear->next=node_p;
   list->rear=node_p;
   (list->count)++;
   return true;

 }


 iter_i++;
 list->pos= list->front;

 while (index!=iter_i) {
   list->pos = list->pos->next;
   iter_i++;
 }



   node_p->next=list->pos->next;
   list->pos->next=node_p;
   (list->count)++;
   return true;


}

bool del_node_at(LLIST* list,unsigned int index){

   if(list->count==0) return false;
   if(index>=list->count) return false;

   if(list->count==1){
     free(list->front);
     list->rear=NULL;
     list->front=NULL;
     list->count=0;
     return true;
   }

   int iter_i=0;
   NODE* pre = NULL;
   list->pos=list->front;

   while(iter_i!=index){

     pre = list->pos;
     list->pos=list->pos->next;
     iter_i++;

   }

  if(index==0){
    list->front=list->pos->next;
    free(list->pos);
    (list->count)--;
    list->pos=NULL;
    return true;
 }
  if(index==list->count-1){
   list->rear=pre;
   pre->next=NULL;
   free(list->pos);
   list->pos==NULL;
   (list->count)--;
   return true;
 }

 else{
   pre->next=list->pos->next;
   free(list->pos);
   list->pos=NULL;
   (list->count)--;
   return true;
 }
 return false;

}


void* get_data_at(LLIST* list,unsigned int index){
   if(index>=list->count) return NULL;

   int iter_i=0;
   list->pos=list->front;

   while(list->pos!=NULL){
     if(iter_i==index)return list->pos->data_ptr;

    list->pos=list->pos->next;
    iter_i++;
  }

  return NULL;

}







void destroy_list(LLIST* list){

   if(list != NULL){

     while(list->count!=0){
       int i = list->count;

       free(list->front->data_ptr);
       del_node_at(list,i);

        i--;
     }



   }



}
