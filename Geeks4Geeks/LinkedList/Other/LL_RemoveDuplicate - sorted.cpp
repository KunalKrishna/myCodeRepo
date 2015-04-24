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

/* Function to remove duplicates from a UNSORTED linked list */
void removeDuplicates(struct node *start){
    struct node* outer = start;
    struct node* inner;
    struct node* dup;

    while(outer != NULL && outer->next != NULL)
    {
        inner = outer;
        while(inner->next != NULL )
        {
            if(outer->data == inner->next->data)
            {
                dup = inner->next;
                inner->next = dup->next;
                free(dup);
            } else
            {
                inner = inner->next;
            }
        }
        outer = outer->next;
    }
}

int main()
{
    node* head = NULL;
    push(&head, 1);
    push(&head, 11);
    push(&head, 1);
    push(&head, 2);
    push(&head, 9);
    push(&head, 10);
    push(&head, 2);

    printf("\nLinked list before duplicate removal  ");
    printList(head);
    printf("Removing Duplicates from UNSORTED Linked List ...");
    removeDuplicates(head);
    printList(head);
}
