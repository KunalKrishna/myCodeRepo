// http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list-by-changing-links/

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


Node pairwiseSwap(Node head){

	if(head == NULL || head->next == NULL ) 
		return head;
	
	Node newHead = head->next;
	Node rest = head->next->next;
	newHead->next= head;
	newHead->next->next = pairwiseSwap(rest);
	
	return newHead;
}

void pairwiseSwap2(Node& head){
	if(head == NULL || head->next == NULL)
	return;
	
	Node prev = head;
	Node curr = head->next;
	
	head = curr;
	while(true){
		Node rest = curr->next;
		curr->next= prev;
		if(rest == NULL || rest->next== NULL){
			prev->next=rest;
			break;
		}
		prev->next = rest->next;
		
		prev= rest;
		curr= rest->next;
	}
}


int main(){
    node* head = NULL;
    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);
	
	printf("before swap\n");
    printList(head);
    
    //head = pairwiseSwap(head);
    printf("after swap\n");
    //printList(head);
    
    pairwiseSwap2(head);
    printList(head);
    
}
