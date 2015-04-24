// http://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
    int val;
    node* next;
};

typedef node* Node;
typedef node** NodeRef;

void push(NodeRef head,int new_data){
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->val = new_data;
    temp->next = (*head);
    (*head) = temp;
}

void printList(Node head){
    printf("\n");
    if(head == NULL){
        printf("\nEmpty List.\n");
    }
    while(head!=NULL){
        printf("%d -> ",head->val);
        head=head->next;
    }
    printf("\n\n");
}
node* newNode(int data){
    node* temp = (node*)malloc(sizeof(struct node));
    temp->val = data;
    temp->next = NULL;
    return temp;
}
struct node* addTwoLists (struct node* first, struct node* second){
    node* res = NULL;
    node* temp;
    node* prev = NULL;
    int sum;
    int carry =0 ;
    while(first || second){

        sum = (first?first->val:0) + (second?second->val:0) + carry; // 0-9 or 10-18
        if(sum>9) {
            carry = 1;
            sum %= 10;
        }else{
            carry =0;
        }
        temp = newNode(sum);
        if(res == NULL){
            res = temp;
        }else{
            prev->next = temp;
        }
        prev = temp;

        if(first)  first  = first->next;
        if(second) second = second->next;
    }
    if(carry){
        prev->next = newNode(1);
    }
    return res;
}

int main(){
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;

    // create first list 7->5->9->4->6
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);

    printf("First List is ");
    printList(first);

    // create second list 8->4
    push(&second, 4);
    push(&second, 8);

    printf("Second List is ");
    printList(second);

    // Add the two lists and see result
    res = addTwoLists(first, second);
    printf("Resultant list is ");
    printList(res);

   return 0;
}
