// http://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
typedef struct node* Node;
typedef struct node** NodeRef;

struct node* newNode(int newData)
{
    struct node* newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(struct node* root)
{
    if(root){
        inOrder(root->left);
            cout<<root->data<<" ";
        inOrder(root->right);
    }
}

void insertNode(Node &root, int key)
{
    if(root == NULL)
        root = newNode(key);
    else{
        if(root->data > key)
            insertNode(root->left, key);
        else
            insertNode(root->right, key);
    }
}

void PrintRange(Node root, int k1, int k2)
{
    if(root==NULL) return;

    if(root->data > k1)
        PrintRange(root->left, k1, k2);

    if(k1 < root->data && root->data < k2){
        cout<<root->data<<" ";
    }

    if(root->data < k2)
        PrintRange(root->right, k1, k2);
}

void PrintRange(Node root, int k1, int k2)
{
    if(root==NULL) return;

    if(root->data > k1)
        PrintRange(root->left, k1, k2);

    if(k1 < root->data && root->data < k2){
        cout<<root->data<<" ";
    }

    if(root->data < k2)
        PrintRange(root->right, k1, k2);
}
int main()
{
    struct node *root = new struct node;
    int k1 = 10, k2 = 25;

    /* Constructing tree given in the above figure */
    root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);

    PrintRange(root, k1, k2);

    return 0;
}
