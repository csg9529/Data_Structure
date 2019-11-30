

#include<stdio.h>
#include<stdlib.h>
#include"ADT_heap.h"


HEAP*
create_heap(int max){

  HEAP* heap = (HEAP*)malloc(sizeof(HEAP));
  heap->last = -1;
  heap->size = 0;
  heap->max_size = max;
  heap->array = (int*)malloc(sizeof(int)*max);
  return heap;
}

int* reheapUp(HEAP* heap, int new_node){
 int* array = heap->array;

  if(heap->size > 1) {

  int parent_index,child_index;
  for(int i;i<heap->size ; i++){
    if(array[i] == new_node){
      child_index = i;
      parent_index =(child_index-1)/2;
    }
  }
  if((heap->array)[(child_index-1)/2] < new_node){
      int tmp;
      tmp = array[child_index];
      array[child_index] = array[parent_index];
      array[parent_index] = tmp;
      heap->array = array;
  }

  if(parent_index!=0){
    array = reheapUp(heap,array[parent_index]);
    heap->array = array;
    }
  }return array;
}

bool insertHeap(HEAP* heap,int last,int data){
  if(heap->size = heap->max_size){
    printf("\nmax size(%d) over \n",heap->max_size);
    return false;
  }
  (heap->array)[last+1] = data;
  heap->size ++;
  heap->last ++;

  heap->array = reheapUp(heap,(heap->array)[heap->last]);


  return true;
}
