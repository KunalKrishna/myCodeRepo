// http://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

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

void inOrder(struct node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
        printf("%d ",root->data);
    inOrder(root->right);
}

int sizeOfTree(struct node* root)
{
    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

int floor(Node root, int input)
{
    if(root==NULL) return 100;

    if(root->data > input)
        return floor(root->left, input);

    int fl = floor(root->right, input);
    return (fl<=input)? fl: root->data;

}

int main(){
    node *root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(14);

    for(int i = 0; i < 16; i++)
        printf("%d  %d\n", i, floor(root, i));

    return 0;
}
