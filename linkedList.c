//*
//LinkedList implementation using recursion
//(C) Stephen Carter
//stephen.carter@mail.mcgill.ca
//

#include <stdlib.h>
#include <stdio.h>


typedef struct node{
  int data;
  struct node *next;
}node;


void addNode(int data_in, node **head){

  if(*head == 0){
    *head = malloc(sizeof(node));
    (*head)->data = data_in;
    (*head)->next = 0;
  } else if(*head != 0)
    addNode(data_in, &((*head)->next));
}

void deleteNode(int data_out, node *head){
  if(head->next->data == data_out){
    node *temp = head->next->next;
    free(head->next);
    head->next = temp;
  }else if(head != 0)
    deleteNode(data_out, head->next);
}

void destroyList(node *head){
  if(head != 0){
    destroyList(head->next);
    free(head);
  }
}

node * reverseList(node *head, node *reverse){
  if(head == 0)
    return reverse;
  else{
    node *current = head;
    head = head->next;
    current->next = reverse;
    return reverseList(head, current);
  }
}

void printList(node *head){
  if(head != 0){
    printf("%d\n", head->data);
    printList(head->next);
  }
}

void main(int argc, char** argv){
  node *head = NULL;

  addNode(5, &head);
  addNode(6, &head);
  addNode(7, &head);
  addNode(10, &head);

  printList(head);

  deleteNode(7, head);

  printList(head);

  head = reverseList(head, NULL);

  printList(head);

  destroyList(head);
}
