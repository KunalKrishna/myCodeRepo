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

/* Function to print reverse of a Linked List */
void printReverse(struct node* head){

    if(head == NULL)
        return;
    printReverse(head->next);
    printf("%d -> ",head->data);
}

int main(){

    node* head = NULL;
    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printList(head);
    printf("\nPrinting reverse of a linked list\n");
    printReverse(head);
}
