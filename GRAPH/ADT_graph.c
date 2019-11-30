#include "ADT_llist.h"
#include "ADT_graph.h"
#include <stdio.h>
#include<stdlib.h>


int compare_vertex(void* x, void* y){
  VERTEX* left = (VERTEX*)x;
  VERTEX* right = (VERTEX*)y;
  return left ->data - right->data;

}
void print_vertex(void* x){
  VERTEX* vertex = (VERTEX*)x;
  printf("- vertex : %c\n", (char)(vertex->data));

}
int compare_arc(void*x, void* y){
  ARC* left = (ARC*)x;
  ARC* right = (ARC*)y;
  return compare_vertex(left->to_vertex,right->to_vertex);
}
void print_arc(void*x){
  ARC* arc = (ARC*)x;
  printf("          -> : %c\n", (char)(arc->to_vertex->data));
}

GRAPH* create_graph(){
  GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
  graph ->vertex_llist= create_list(compare_vertex,print_vertex);
  return graph;
}



bool
g_insert_vertex(GRAPH* graph,
                int data){
    VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));
    new_vertex->data =data;
    new_vertex->arc_llist = create_list(compare_arc,print_arc);

    int vertex_loc = find_data(graph->vertex_llist, new_vertex);

    if(vertex_loc != -1){
      free(new_vertex);
      return false;

    }
    return add_node_at(
            graph->vertex_llist,
            graph->vertex_llist->count,
            new_vertex);

}

void print_vertex_all(GRAPH* graph){
  NODE* pos = graph->vertex_llist ->front;
  while(pos!= NULL){
    print_vertex(pos->data_ptr);
    pos= pos->next;
  }
}
bool
g_insert_arc(GRAPH* graph, int from, int to){
  //  find data 함수를 사용하기위해 템프 벌택스를 선언 및 초기화;
  VERTEX tmp_vertex1;
  tmp_vertex1.data = from;
  tmp_vertex1.arc_llist= NULL;
  // 벌택스 리스트에서 from 값이 있는지 찾기 (예외처리)
  int vertex_loc = find_data(graph->vertex_llist,&tmp_vertex1);
  if(vertex_loc== -1){
    printf("from_vertex %c : not found\n",(char)from);
    return false;
  }
//from 벌택스를 찾아서 저장
  VERTEX* from_vertex = (VERTEX*)get_data_at(graph->vertex_llist,vertex_loc);
// to 값을 넣기전 그값이 벌택스에 있는지 확인 해야함
  VERTEX tmp_vertex2;
  tmp_vertex2.data = to;
  tmp_vertex2.arc_llist= NULL;

  vertex_loc = find_data(graph->vertex_llist,&tmp_vertex2);
  if(vertex_loc == -1){
    printf("to_vertex %c : not found\n",(char)from);
    return false;
  }
  // 있으면 to 벌택스 만들어주기

  VERTEX* to_vertex = (VERTEX*)get_data_at(graph->vertex_llist,vertex_loc);
  //  아크를 만들어서 뒤쪽에 넣어주기
  ARC* new_arc = (ARC*)malloc(sizeof(ARC));
  new_arc ->to_vertex = to_vertex;

  int arc_loc =find_data(from_vertex->arc_llist,new_arc);
  if(arc_loc!= -1){
    free(new_arc);
    return false;
  }
  return add_node_at(
  from_vertex->arc_llist,
  from_vertex->arc_llist->count,
  new_arc
);

}
void
print_arc_all(GRAPH* graph){
  NODE* vertex_cur =graph->vertex_llist->front;

  while(vertex_cur!=NULL){
    printf("VERTEX : %c\n",(char)((VERTEX*)vertex_cur->data_ptr)->data);

    NODE* pos_arc= ((VERTEX*)(vertex_cur->data_ptr))->arc_llist->front;
    while(pos_arc != NULL){
      print_arc(pos_arc->data_ptr);
      pos_arc = pos_arc->next;
    }
    vertex_cur = vertex_cur->next;
  }
}

bool g_delete_vertex(GRAPH* graph, int data){
  if(graph->vertex_llist->count == 0)
  return false;

  bool flag = false;

  VERTEX del_vertex;
  del_vertex.data = data;
  del_vertex.arc_llist= NULL;

  int del_index = find_data(graph->vertex_llist,&del_vertex);
  if(del_index == -1)return flag;

  flag = del_node_at(graph->vertex_llist,del_index);

  ARC del_arc;
  del_arc.to_vertex = &del_vertex;
  NODE* pos_vertex = graph->vertex_llist->front;

  while(pos_vertex!= NULL){
    del_index = find_data(((VERTEX*)(pos_vertex->data_ptr))->arc_llist,&del_arc);
    if(del_index != -1)
      flag = del_node_at(((VERTEX*)(pos_vertex->data_ptr))->arc_llist,del_index);

    pos_vertex = pos_vertex = pos_vertex->next;

  }
  return flag;
}
