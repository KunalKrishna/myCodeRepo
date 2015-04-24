// http://www.geeksforgeeks.org/rotate-a-linked-list/

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

int sizeOfList(node* head){
    int K=0;
    while(head){
        head= head->next;
        K++;
    }
    return K;
}

void rotateK(NodeRef head_ref, int k){
	Node tail = *head_ref;
	Node head = *head_ref;	
	
	k = k%sizeOfList(head);
	
	if(head == NULL || k==0) return;
	
	// move tail to previous node of kth node
	for(int i =0; i<k-1; i++){
		tail = tail->next;
	}
	// update head_ref to point kth node
	*head_ref = tail->next;
	// set the last node of first sublist to NULL
	tail->next = NULL;
	tail = *head_ref;

	// reach the end node of second sublist	
	while(tail->next!=NULL){
		tail = tail->next;
	}
	// make it point to the old head
	tail->next = head;
}

int main(){
	/* Start with the empty list */
    struct node* head = NULL;
 
    // create a list 10->20->30->40->50->60
    for (int i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    rotateK(&head, 7);
 
    printf("\nRotated Linked list \n");
    printList(head);
 
    return (0);
}

