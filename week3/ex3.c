#include<stdio.h>
#include<stdlib.h>

struct node{
  int value;
  struct node *next;
};

void printList(struct node *n){
  while (n != NULL){
     printf(" %d ", n->value);
     n = n->next;
  }
    printf("\n");

}

void insert(struct node *n, struct node *head){
  struct node* last = head; 
  struct node* someNode;     
  while (last != NULL){
     someNode = last;
     last = last->next;
  }
  someNode->next = n; 
}

void delete(struct node *head){
  struct node* last = head; 
  struct node* someNode;    
  someNode = last;
  while (last != NULL){
     if(last->next == NULL){
        someNode->next = NULL;
     }
     someNode = last;
     last = last->next;
  }
}

int main(){
  struct node* head = (struct node*)malloc(sizeof(struct node)); 
  struct node* another = (struct node*)malloc(sizeof(struct node));
  
  head->value = 1;
  head->next = another;  
  another->value = 2; 
  another->next = NULL;  
  
  printList(head);
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->value = 3;
  newNode->next = NULL;
  insert(newNode, head);
  printList(head);
  delete(head);
  printList(head);
}