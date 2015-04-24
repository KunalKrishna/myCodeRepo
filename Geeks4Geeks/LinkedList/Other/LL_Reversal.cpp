#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct node* createNode(int data)
{
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
}

void push(struct node** head,int new_data)
{
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

void reverse(struct node** head_ref)
{
    struct node* current = *head_ref;
    struct node* prev = NULL;
    struct node* next;

    if( *head_ref != NULL && (*head_ref)->next != NULL)
    {
        while(current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head_ref = prev;
    }
}

void recursiveReverse(struct node** head_ref)
{
    struct node* first;
    struct node* rest;

    // empty list OR List has only one node
    if(*head_ref == NULL || (*head_ref)->next == NULL)
        return;

    first = *head_ref;
    rest = first->next;

    recursiveReverse(&rest);
    first->next->next = first;
    first->next = NULL;

    *head_ref = rest;
}

int main()
{
    node* head = NULL;
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printList(head);
    printf("Reversing Iteratively ...\n");
    reverse(&head); // try : 1. empty list 2. list having single node.
    printList(head);
    printf("Reversing Recursively ...\n");
    recursiveReverse(&head);
    printList(head);

}
