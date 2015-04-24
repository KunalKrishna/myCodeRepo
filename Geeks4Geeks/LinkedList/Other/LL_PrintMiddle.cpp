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

void printMiddle(struct node* head)
{
    struct node * slow = head;
    struct node * fast = head;

    if(head == NULL){
        printf("Empty List!");
        return ;
    }
    /*while(fast != NULL){
        fast=fast->next;
        if(slow != NULL && fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }*/
    while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
    printf("\nMiddle element = [%d] \n",slow->data);
}

int main()
{
    node* head = NULL;
    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printList(head);;

    printMiddle(head);

}
