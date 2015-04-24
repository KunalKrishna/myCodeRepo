// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    node* next;
};
typedef node* Node;
typedef node** NodeRef;

void push(NodeRef headRef, int new_data){
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*headRef);
    (*headRef) = temp;
}

void printList(Node head){
    printf("\n");
    /*
    if(head == NULL){
        printf("\nEmpty List.\n");
    }*/
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n\n");
}

void removeLoop(Node, Node);

int detectAndRemoveLoop(Node head){
	if(!head) return 1;
	Node slow_p = head;
	Node fast_p = head;
	
	while(slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p){
			removeLoop(slow_p, head);
			return 1;
		}
	}
	return 0; // NO LOOP DETECTED
}

void removeLoop(Node loop_ptr, Node head){
	Node ptr1, ptr2;
	ptr1 = head;
	while(1){
		ptr2 = loop_ptr;
		while( ptr2->next != loop_ptr && ptr2->next != ptr1){
			ptr2 = ptr2->next;
		}
		if( ptr2->next == ptr1)
			break;
		else
			ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
}

int main(){
    /* Start with the empty list */
    struct node* head = NULL;
 
    push(&head, 10);
    push(&head, 4);
    push(&head, 15);
    push(&head, 20);
    push(&head, 50);
    
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 	
    detectAndRemoveLoop(head);
 	
    printf("Linked List after removing loop \n");
    printList(head);
 
    getchar();
    return 0;
}
