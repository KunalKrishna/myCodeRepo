// http://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/

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

/*This solution uses the temporary dummy to build up the result list */
struct node* sortedIntersect(struct node* a, struct node* b){
    struct node dummy;
    dummy.next = NULL;
    struct node* res = &dummy;

    while(a != NULL && b!= NULL)
    {
        if(a->data == b->data)
        {
            push( &(res->next) , a->data );
            a= a->next;
            b= b->next;
        } else if(a->data < b->data)
        {
            a= a->next;
        } else
        {
            b= b->next;
        }
    }
    return( dummy.next) ;
};

int main(){
    struct node* a = NULL;
    struct node* b=NULL;
    struct node* intersect = NULL;
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    printList(a);
    printList(b);
    intersect = sortedIntersect(a, b);
    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);
}
