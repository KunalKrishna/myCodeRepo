#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

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

    /*void append(struct node** head_ref, int new_data){
    struct node* last = *head_ref;

    struct node* temp = (struct node*) malloc(sizeof( struct node));
    temp->data = new_data;
    temp->next = NULL;

    while(last != NULL){
        last = last->next;
    }
    last = temp;
}*/
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

/* http://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/ */
int GetNthRec(struct node* head, int index)
{
    if(index==0 && head != NULL)
        return head->data;

    if(head->next !=NULL && index>=1)
        return GetNthRec(head->next,index-1);

    printf("Try smaller index!!!\n");
    assert(0);
}

int GetNth(struct node* head, int index)
{

    int count = 0;
    struct node* current = head;
    while(current != NULL)
    {
        if(count == index){
            return current->data;
        }
        current = current->next;
        count++;
    }
    assert(0);
}

/* http://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/ */
void printNthFromLast(struct node *head, int N)
{
    struct node* back = head;
    struct node* front = head;

    int count =0;
    while(count < N)
    {
        if(front == NULL)
        {
            printf("%d is greater than the no. of nodes in list", N);
            return;
        }
        front = front->next;
        count++;
    }

    while(front != NULL)
    {
        back = back->next;
        front = front->next;
    }
    printf("\nNode no. %d from last is %d \n", N, back->data);
}

/* http://www.geeksforgeeks.org/given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/ */
void deleteNode(struct node *node_ptr)
{
    printf("\nDeleting %d \n\n",node_ptr->data);

    struct node*temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    free(temp);
}

/* http://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/ */
void deleteList(struct node** head_ref)
{
    struct node * temp = *head_ref;

    while(*head_ref != NULL){
        temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
    }
}

/* http://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/ */
int main()
{
    node* head = NULL;
    push(&head, 10);
    push(&head, 8);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 2);

    printf("SIZE = %d ", sizeOfList(head));
    printList(head);

    printf("%d Occured %d times in the list \n", 8, countX( head, 8));

    // LIST UPDATION
    printf("\nInserting after given node ...\n");
    insertAfter(head , 3);
    printList(head);

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 20;
    temp->next = NULL;
    printf("\nsorted insert ...\n");
    sortedInsert(&head,temp);
    printList(head);

    printf("\nAppending to the List ...\n");
    append(&head,0);
    printList(head);

    // LIST TRAVERSAL

    printf("Element at index 0 is %d\n", GetNthRec(head, 0));
    printf("Element at index 2 is %d\n", GetNthRec(head, 2));
    printf("Element at index 5 is %d\n", GetNthRec(head, 5));
    //printf("Element at index 8 is %d\n", GetNthRec(head, 8));

    printf("Element at index 1 is %d\n", GetNth(head, 1));
    printf("Element at index 3 is %d\n", GetNth(head, 3));
    printf("Element at index 5 is %d\n", GetNth(head, 5));
    //printf("Element at index 8 is %d\n", GetNth(head, 8));


    printNthFromLast(head,7);

    //LIST DELETION
    printf("\nDeleting Node ...\n");
    deleteNode(head->next);//exept the last node of list
    printList(head);

    printf("\nDeleting List ...\n");
    deleteList(&head);
    printList(head);

}
