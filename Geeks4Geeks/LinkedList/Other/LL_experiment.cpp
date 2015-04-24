#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

typedef struct node* Node;
typedef struct node** NodeRef;
/* Add a node at the front: (A 4 steps process) */
void push(struct node** head,int new_data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
}

/* Add a node after a given node: (5 steps process) */
void insertAfter(struct node* prev_node, int new_data)
{
    if(prev_node == NULL)
        return;

    struct node* temp = (struct node*) malloc(sizeof( struct node));
    temp->data = new_data;
    temp->next = prev_node->next;
    prev_node->next = temp;
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    struct node* current ;
    if(*head_ref == NULL ||
                            (*head_ref)->data > new_node->data ){
        new_node->next = *head_ref;
        *head_ref = new_node;
    } else {
        current = *head_ref;
        while(current->next !=NULL && (current->next)->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

}
/* Add a node at the end: (6 steps process) */
void append(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node *last = *head_ref;  /* used in step 5*/
    new_node->data  = new_data;
    new_node->next = NULL;

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

/* http://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/ */
int countX(struct node* head, int X)
{
    int countX =0;
    struct node* current = head;
    while(current != NULL)
    {
        if(current->data == X )
            countX++;
        current = current->next;
    }
    return countX;
}

void deleteNode(struct node *node_ptr)
{
    printf("\nDeleting %d \n\n",node_ptr->data);

    struct node*temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

/* experiment 01 */
void deleteList( Node& head_ref)
{
    struct node * temp = head_ref;

    while(head_ref != NULL){
        temp = head_ref;
        head_ref = (head_ref)->next;
        free(temp);
    }
}

int twice(int& a){
	a=9;
}
int main()
{
    Node head = NULL;
    push(&head, 10);
    push(&head, 8);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printf("SIZE = %d ", sizeOfList(head));
    printList(head);
    deleteList(head);
	printList(head);
	
	int a =7;
	twice(a);
	printf("%d",a);
	
    return 0;
}
