// http://www.geeksforgeeks.org/print-nodes-dont-sibling-binary-tree/

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

Node newNode(int newData)
{
    //struct node* newNode = (struct node*)malloc(sizeof(struct node));
    Node newNode = new node;
    newNode->data = newData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
        cout<<root->data<<" ";
    inOrder(root->right);
}

bool isLeaf(Node root)
{
    if(!root) return false;
    if(!root->left && !root->right)
        return true;
    return false;
}

void printSiblingLessNodes(Node root)
{
    if(!root) return;
    if( root->left && !root->right){
        cout<<root->left->data<<" ";
    }
    if( root->right && !root->left ){
        cout<<root->right->data<<" ";
    }
    printSiblingLessNodes(root->left);
    printSiblingLessNodes(root->right);
}

int main()
{
    Node root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(5);
    root->right->left->left = newNode(6);

    cout<<"Print all nodes that dont have sibling "<<endl;
    printSiblingLessNodes(root);
    return 0;
}
