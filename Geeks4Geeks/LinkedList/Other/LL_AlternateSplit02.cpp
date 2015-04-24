// http://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

using namespace std;

struct node{
    int data;
    node* next;
};

typedef struct node* Node;
typedef struct node** NodeRef;

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


void MoveNode(struct node** destRef, struct node** sourceRef) 
{
	Node newNode = *sourceRef;
	
	*sourceRef = (*sourceRef)->next;
	newNode->next= *destRef;
	*destRef = newNode;
}

/* Given the source list, split its nodes into two shorter lists.
  If we number the elements 0, 1, 2, ... then all the even elements
  should go in the first list, and all the odd elements in the second.
  The elements in the new lists may be in any order. */
void AlternatingSplit2(struct node* source, struct node** aRef, struct node** bRef)
{
	Node current = source;
	while(current != NULL){
		MoveNode(aRef, &current);
		if(current != NULL){
			MoveNode(bRef, &current);
		}
	}
}

// an alternative approach which builds the sub-lists in the same order as the source list
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef)
{
	struct node aDummy;
	Node aTail = &aDummy;
	struct node bDummy;
	Node bTail = &bDummy;
	struct node* current = source;
	aDummy.next = NULL;
	bDummy.next = NULL;
	
	while(current != NULL){
		MoveNode(&(aTail->next), &current);
		aTail = aTail->next;
		if(current != NULL){
			MoveNode(&(bTail->next), &current);
			bTail = bTail->next;
		}
	}
	*aRef = aDummy.next;
	*bRef = bDummy.next;
}

int main(){
    Node head = NULL;
    Node a = NULL;
    Node b = NULL;
    
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);                                    
	push(&head, 0);
    
	printf("\n Original linked List:  ");
	printList(head); 
	
	/* Remove duplicates from linked list */
	AlternatingSplit(head, &a, &b); 
	
	printf("\n Resultant Linked List 'a' ");
	printList(a);            
	
	printf("\n Resultant Linked List 'b' ");
	printList(b);

    return 0;
}