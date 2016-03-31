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

int detectLoop(node *head){
  node* first = head;
  node* second = head;

  while(first != NULL && second != NULL){
    first = first->next;

    if(second->next != NULL)
      second = second->next->next;
    else
      return 0;
    if(second == first){
      return 1;
    }

  }
  return 0;
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printList(node *head){
  if(head != 0){
    printf("%d\n", head->data);
    printList(head->next);
  }
}
node* merge_sorted(node *in1, node *in2){
	//node *in1 = list1;
	//node *in2 = list2;
	node *merged = NULL;
	node **merging = &merged;
	while(in1 != NULL && in2 != NULL){
		if(in1->data < in2->data){
			(*merging) = in1;
			in1 = in1->next;
		}else{
			(*merging) = in2;
			in2 = in2->next;
		}
		merging = &((*merging)->next);
	}
	if(in1 == NULL){
		*merging = in2;
		return merged;
	}else if(in2 == NULL){
		*merging = in2;
		return merged;
	}
}

void main(int argc, char** argv){
  node *head = NULL;
  node *test = NULL;
  node *merged = NULL;

  addNode(5, &head);
  addNode(6, &head);
  addNode(7, &head);
  addNode(10, &head);
  
  addNode(4, &test);
  addNode(8, &test);
  addNode(11, &test);

  merged = merge_sorted(head, test);

  printList(merged);

  //head->next->next->next->next = head->next;
 if(detectLoop(head)){
    printf("loop found\n");
    exit(0);
  }
 // printList(head);

  deleteNode(7, head);

 // printList(head);

  head = reverseList(head, NULL);

  //printList(head);

  destroyList(head);
}
