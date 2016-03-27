#include <stdlib.h>
#include <stdio.h>


typedef struct node{
  int data;
  struct node* next;
}node;


void enqueue(int data, node** queue){
  if(*queue == 0){
    *queue = malloc(sizeof(node));
    (*queue)->next = NULL;
    (*queue)->data = data;
  }else{
    enqueue(data,&((*queue)->next));
  }
}

int dequeue(node** queue){
  if(*queue == 0){
    return;
  }else{
    node* temp = *queue;
    *queue = (*queue)->next;
    int value = temp->data;
    free(temp);
    return value;
  }
}

int peek(node* queue){
  if(queue == 0){
    return;
  }else{
    return queue->data;
  }
}

void printQueue(node *queue){
  if(queue != 0){
    printf("%d\n", queue->data);
    printQueue(queue->next);
  }
}

void main(int argc, char** argv){
  node *top = NULL;

  enqueue(5, &top);
  enqueue(6, &top);
  printQueue(top);
  printf("dequeuing\n");
  printf("%d\n", dequeue(&top));
  printQueue(top);
  enqueue(7, &top);
  peek(top);
  printQueue(top);
  enqueue(10, &top);
  printQueue(top);
  dequeue(&top);
  dequeue(&top);
  printQueue(top);
}
