// http://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
// @todo (kunalkrishna#1#): finish it.

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

struct node* newNode(int newData)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct node* root){

    if(root == NULL)
        return;
    inOrder(root->left);
        printf("%d ",root->data);
    inOrder(root->right);
}

int sizeOfTree(struct node* root){

    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

bool isSameBST(int a[], int b[], int n)
{

}

int main(){

    int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n=sizeof(a)/sizeof(a[0]);
    printf("%s\n", isSameBST(a, b, n)?
         "BSTs are same":"BSTs not same");
    return 0;
}
