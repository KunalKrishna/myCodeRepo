// http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

struct node* newNode(int newData)
{
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int sizeOfTree(struct node* root)
{
    if(root == NULL){
        return 0;
    }
    return sizeOfTree(root->left)+ 1 +sizeOfTree(root->right);
}

void inOrder(struct node* root)
{
    if(root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void mirror(struct node** root)
{
    struct node* temp;
    if(*root == NULL) return;

    // first swap
    temp = (*root)->right;
    (*root)->right = (*root)->left;
    (*root)->left = temp;

    // then go down
    mirror(&((*root)->left));
    mirror(&((*root)->right));
}

int main(){

    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(7);

    cout<<"Original tree Inorder ";
    inOrder(root);
    mirror(&root);

    cout<<"\nMirror   tree Inorder ";
    inOrder(root);
    return 0;
}
