// http://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/

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

void moveToFront(struct node** head_ref){
    struct node* last;
    struct node* second_last;
    if(*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    last = *head_ref;
    while((last->next) != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

int main()
{
    node* head = NULL;
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 1);

    printList(head);

    moveToFront(&head);

    printList(head);

}
