#include <stdlib.h>
#include <stdio.h>

typedef struct node{
  int key;
  struct node *left;
  struct node *right;
}node;



void destroyTree(node *in){

  if(in != 0){
    destroyTree(in->left);
    destroyTree(in->right);
    free(in);
  }
}

void insert(int key_in, node **start){

  if(*start == 0){
    *start = malloc(sizeof(node));
    (*start)->key = key_in;
    (*start)->left = 0;
    (*start)->right = 0;
  }else if(key_in < (*start)->key){
    insert(key_in, &(*start)->left);
  }else if(key_in > (*start)->key){
    insert(key_in, &(*start)->right);
  }
}

node *search(int key, node *start){
  if(start != 0){
    if(key == start->key)
      return start;
    else if(key < start->key)
      return search(key, start->left);
    else if(key > start->key)
      return search(key, start->right);
  }else
    return 0;
}

void printPreorder(node *root){
  if(root != 0){
    printf("%d\n", root->key);
    printPreorder(root->left);
    printPreorder(root->right);
  }
}

void printInorder(node *root){
  if(root != 0){
    printInorder(root->left);
    printf("%d\n", root->key);
    printInorder(root->right);
  }
}

void printPostorder(node *root){
  if(root != 0){
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d\n", root->key);
  }
}

int main(int argc, char** argv){
  node *root = NULL;

  insert(5, &root);
  insert(10, &root);
  insert(8, &root);
  insert(3, &root);
  insert(4, &root);

  printPreorder(root);
  printInorder(root);
  printPostorder(root);

  printf("%d was found\n", (search(8, root)->key));

  destroyTree(root);
}
