#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct node* createNode(int data)
{
    struct node* temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
}

void push(struct node** head,int new_data)
{
    struct node* temp = (struct node*) malloc(sizeof( struct node));

    temp->data = new_data;
    temp->next = (*head);
    (*head) = temp;
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

int getCount(struct node* head)
{
    int count = 0;
    struct node* current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    return count;
}

void reverse(struct node** );
bool compareList(struct node*, struct node*);

bool isPalindrome(struct node* head)
{
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;


    if(head != NULL && head->next != NULL)
    {
        while(fast_ptr != NULL && fast_ptr->next !=NULL)
        {

        }
    }

}


int main()
{
  node* head1 = NULL;

  printList(head1);

  if(isPalindrome(head1))
  {
      printf("The list is a plaindrome");
  }else
  {
      printf("not a palindrome");
  }
}
