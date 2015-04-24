#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node{
    int data;
    node* next;
};

struct node* createNode(int data){
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
}

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

int getCount(struct node* head){
    int count = 0;
    struct node* current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    return count;
}

int _getIntersectionPoint(int diff, struct node* longerList, struct node* shorterList){
    struct node* current1 = longerList;
    struct node* current2 = shorterList;

    for(int i=0; i<diff; i++){
        if(current1 == NULL)
            return -1;
        current1=current1->next;
    }
    while(current1!=NULL && current2!=NULL){
            if(current1 == current2){
                return current1->data;
            }
        current1=current1->next;
        current2=current2->next;
    }
    return -1;
}

int getIntersectionPoint(struct node* head1,struct node* head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    if(c1 > c2){ //head1 is longer listn
        return _getIntersectionPoint(c1-c2, head1, head2);
    }else{
        return _getIntersectionPoint(c2-c1, head2, head1);
    }
}

int main()
{
  node* head1 = NULL;
  node* head2 = NULL;

  node* temp15 = createNode(15);
  node* temp30 = createNode(30);

  head1 = createNode(3);
  head1->next= createNode(6);
  head1->next->next= createNode(9);
  head1->next->next->next= temp15;
  head1->next->next->next->next= temp30;

  head2 = createNode(10);
  head2->next = temp15;
  head2->next->next = temp30;

  printList(head1);
  printList(head2);

  printf("Intersection point at node %d ", getIntersectionPoint(head1,head2));

}
