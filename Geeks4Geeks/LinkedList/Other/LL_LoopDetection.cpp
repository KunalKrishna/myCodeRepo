// http://www.geeksforgeeks.org/write-a-c-function-to-detect-loop-in-a-linked-list/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node{
    int data;
    node* next;
};

struct node* createNode(int data){
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
}

void push(struct node** head,int new_data){
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(struct node* head){
    printf("\n");
    if(head == NULL){
        printf("\nEmpty List.\n");
        return;
    }
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("\n\n");
}

int detectLoop(struct node* head){
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;

    while(fast_ptr !=NULL &&
              fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(slow_ptr == fast_ptr){
                printf("Loop detected!\n");
                return 1;
            }
        }
    return 0;
}
int main()
{
  /* Start with the empty list */
  struct node* head = NULL;

  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 10);

  /* Create a loop for testing */
  head->next->next->next->next = head;
  detectLoop(head);

  getchar();
}
