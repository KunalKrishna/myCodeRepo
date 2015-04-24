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

void reorderList2(node *head) {
    if(head == NULL || head->next==NULL) return;

    node* current = head;
    while(current->next != NULL && current->next->next !=NULL){

        node* tail = current;
        node* temp = current->next;
        while(tail->next != NULL && tail->next->next !=NULL){
            tail = tail->next;
        }
        current->next = tail->next;
        current->next->next=temp;
        tail->next = NULL;
        current = temp;
    }
}

void reverseList(struct node** head_ref)
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

void reorderList(node *head) {
        if(head == NULL || head->next==NULL) return;

        node* slow = head;
        node* fast = head;

        while(fast->next !=NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        //slow denotes middle node now
        node* rest = slow->next;
        reverseList(&rest);
        slow->next = NULL;

        printf("head : ");
        printList(head);

        printf("rest reversed part : ");
        printList(rest);

        // now merge the head and rest
        node* first = head;
        while(rest != NULL && first != NULL ){
            node* temp = rest;
            rest = rest->next;
            temp->next = first->next;
            first->next=temp;
            first = first->next->next;
        }

}

int main()
{
    node* head = NULL;
    for(int i=5; i>0; i--){
        push(&head, i);
    }

    printList(head);
    reorderList(head);
    printList(head);

    return 0;
}
