// http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/

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

int max(int a, int b)
{
    return (a>b)?a:b;
}

int maxDepth(struct node* root)
{
//    return (root)? ( 1 + max(maxDepth(root->left), maxDepth(root->right)))
//                    : 0;
    if(root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){

    struct node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(7);

    cout<<"Hight of tree is "<< maxDepth(root);
    return 0;
}
