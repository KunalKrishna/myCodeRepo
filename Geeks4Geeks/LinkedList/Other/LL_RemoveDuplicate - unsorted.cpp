// http://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
};

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
    }
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("\n\n");
}

// remove duplicate in a sorted Linked List
void removeDuplicate(struct node* head){
    struct node* current = head;
    struct node* next_next;
    if(current == NULL )
        return;

    while( current->next != NULL)
    {
        if(current->data == (current->next)->data)
        {
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        } else
        {
            current = current->next;
        }
    }
}

int main()
{
    node* head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);
    push(&head, 2);

    printf("\nLinked list before duplicate removal  ");
    printList(head);
    printf("Removing Duplicates from SORTED Linked List ...");
    removeDuplicate(head);
    printList(head);
}
