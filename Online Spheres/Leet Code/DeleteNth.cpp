#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

void push(struct node** head,int new_data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(struct node* head)
{
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

int sizeOfList(node* head){
    int K=0;
    while(head){
        head= head->next;
        K++;
    }
    return K;
}

node *removeNthFromEnd(node *head, int n) {
    int size = sizeOfList(head);
    if( !size || n> size) return head;
    node* temp;
    node* current = head;
    int diff = size - n-1;
    //printf("%d",diff);
    if(n==size){
        if(n==1) return NULL;
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while(diff--){
        current = current->next;
    }
    //printf("%d",current->data);
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}


int main()
{
    node* head = NULL;
    for(int i=1; i>0; i--){
        push(&head, i);
    }

    printList(head);
    head = removeNthFromEnd(head,1);
    printList(head);

    return 0;
}
