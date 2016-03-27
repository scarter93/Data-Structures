#include <stdlib.h>
#include <stdio.h>


typedef struct node{
  int data;
  struct node *next
}node;


void push(int data, node **top){
  if(*top == 0){
    *top = malloc(sizeof(node));
    (*top)->next = NULL;
    (*top)->data = data;
  }else{
    node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
  }
}

int pop(node **top){
  int value;
  if(*top == 0){
    return;
  }else{
    node* temp = *top;
    *top = (*top)->next;
    value = temp->data;
    free(temp);
    return value;
  }
}

int peek(node* top){
  if(top == 0){
    return;
  }else{
    return top->data;
  }
}

void printStack(node *top){
  if(top != 0){
    printf("%d\n", top->data);
    printStack(top->next);
  }
}

void main(int argc, char** argv){
  node *top = NULL;

  push(5, &top);
  push(6, &top);
  printStack(top);
  printf("popping\n");
  printf("%d\n", pop(&top));
  printStack(top);
  push(7, &top);
  peek(top);
  printStack(top);
  push(10, &top);
  printStack(top);
  pop(&top);
  pop(&top);
  printStack(top);
}
