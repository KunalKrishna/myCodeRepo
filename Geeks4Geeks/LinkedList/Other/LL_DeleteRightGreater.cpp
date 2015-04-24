// http://www.geeksforgeeks.org/delete-nodes-which-have-a-greater-value-on-right-side/
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

void _delLesserNodes(struct node* head){

    struct node* current =head;
    struct node* temp;

    while(current != NULL && current->next != NULL)
    {
        if(current->data > (current->next)->data)
        {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        } else {
            current= current->next;
        }
    }

}
void delLesserNodes(struct node** head_ref){

    if( *head_ref == NULL || (*head_ref)->next == NULL){
        return ;
    }

    reverseList(head_ref);

    _delLesserNodes(*head_ref);

    reverseList(head_ref);
}

int main(){

    struct node *head = NULL;

    /* Create following linked list
      12->15->10->11->5->6->2->3 */
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

    /* Create following linked list
    10->20->30->40->50->60->*/
    /*
    push(&head,60);
    push(&head,50);
    push(&head,40);
    push(&head,30);
    push(&head,20);
    push(&head,10);
    */
    /*
    push(&head,10);
    push(&head,20);
    push(&head,30);
    push(&head,40);
    push(&head,50);
    push(&head,60);

    */
    printf("Given Linked List: ");
    printList(head);

    delLesserNodes(&head);

    printf("\nModified Linked List: ");
    printList(head);
}
