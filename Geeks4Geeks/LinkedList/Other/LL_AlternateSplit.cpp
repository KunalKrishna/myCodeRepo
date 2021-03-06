// http://www.geeksforgeeks.org/alternating-split-of-a-given-singly-linked-list/

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

void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = NULL;
	struct node *last = *head_ref; 
	
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef){
	int count = 0;
	while(source != NULL){
		if(count%2 == 0){
			append(aRef, source->data);
		} else{
			append(bRef, source->data);
		}
		
		source = source->next;
		count++;
	}
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
