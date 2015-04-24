// http://www.geeksforgeeks.org/identical-linked-lists/
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

bool areIdentical(struct node* a, struct node* b){

    while(1)
    {
        if(a == NULL && b == NULL)
            return 1;
        if(a == NULL && b!= NULL)
            return 0;
        if(a != NULL && b== NULL)
            return 0;
        if( a->data != b->data )
            return 0;

        a = a->next;
        b = b->next;
    }
}

bool areIdenticalRec(struct node* a, struct node* b){

    if(a == NULL && b == NULL)
            return 1;
    if(a == NULL && b!= NULL)
        return 0;
    if(a != NULL && b== NULL)
        return 0;
    if( a->data != b->data )
        return 0;

    return areIdenticalRec(a->next, b->next);
}


int main(){
    struct node *a = NULL;
    struct node *b = NULL;

    /* The constructed linked lists are :
    a: 3->2->1
    b: 3->2->1 */
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);

    printList(a);

    push(&b, 1);
    push(&b, 2);
    push(&b, 3);

    printList(b);

    if(areIdentical(a, b) == 1)
    //if(areIdenticalRec(a, b) == 1)
        printf(" Linked Lists are identical ");
    else
        printf(" Linked Lists are not identical ");;
}
