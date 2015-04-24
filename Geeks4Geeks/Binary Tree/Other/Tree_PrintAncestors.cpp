// http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

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

struct node* newNode(int newData){

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

bool printAncestors(struct node *root, int target){

    if (root == NULL){
        return false;
    }

    if(root->data == target)
}

int main(){

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Size of tree is %d \n", sizeOfTree(root));
    getchar();
}
