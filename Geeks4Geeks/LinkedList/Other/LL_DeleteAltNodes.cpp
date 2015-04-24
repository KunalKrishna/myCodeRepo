// http://www.geeksforgeeks.org/delete-alternate-nodes-of-a-linked-list/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
};

typedef node* Node;
typedef node** NodeRef;

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

/*
void deleteAlt(Node head){
	Node current = head;
	Node temp;
	while( current &&  (current->next)){
		temp = current->next;
		current->next = (current->next)->next;
		free(temp);
		current = current->next;
	}
}
*/

void deleteAlt(Node head){
	Node temp;
	while( head &&  (head->next)){
		temp = head->next;
		head->next = (head->next)->next;
		free(temp);
		head = head->next;
	}
}
/*
void deleteAltRec(Node head){
	if( head == NULL  ) return ;
	
	Node temp = head->next ;
	
	if( temp == NULL) return;
	
	head->next= temp->next;
	free(temp);
	deleteAltRec(head->next);
	
}
*/

void deleteAltRec(Node head){
	Node temp;
	if( head != NULL && head->next!=NULL) {
		temp = head->next;
		head->next= temp->next;
		free(temp);
		deleteAltRec(head->next);	
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

    printList(head);
//  deleteAlt(head);
    deleteAltRec(head);
    printList(head);
}
