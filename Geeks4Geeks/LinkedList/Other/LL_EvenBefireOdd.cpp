// http://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
};

typedef node* Node;
typedef node** NodeRef;

void push(NodeRef head,int new_data){
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(Node head){
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

void insertAfter(struct node* prev_node, struct node* temp)
{
    if(prev_node == NULL)
        return;

    temp->next = prev_node->next;
    prev_node->next = temp;
}

void placeBeforeFirstOdd(struct node* head, struct node* oddNode)
{
	// while even continue
    while( head->next != NULL && !( (head->next)->data%2 )  ){
    	head = head->next;
    }
	insertAfter(head,oddNode);   
}

void segregateEvenOdd(node** head_ref){
	node* temp;
	// base case : single node list  or empty list already processed
	if( *head_ref == NULL || (*head_ref)->next == NULL ) return;
	
	segregateEvenOdd( &((*head_ref)->next));
	if((*head_ref)->data % 2)//ODD
	{
		temp = *head_ref;
		*head_ref = (*head_ref)->next;
		placeBeforeFirstOdd(*head_ref, temp);
	}
}

int main(){
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
      17->15->8->12->10->5->4->1->7 */
 	push(&head, 6);
    push(&head, 7);
 	push(&head, 1);
    push(&head, 4);
    push(&head, 5);
    push(&head, 10);
    push(&head, 12);
    push(&head, 8);
    push(&head, 15);
    push(&head, 17);
    	
    printf("\n Original Linked list ");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\n Modified Linked list ");
    printList(head);
 
    return 0;
}
